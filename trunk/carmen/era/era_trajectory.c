/***************************************************************************
 *   Copyright (C) 2009 by Ralf Kaestner                                   *
 *   ralf.kaestner@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <signal.h>

#include <control/closed_loop.h>

#include "era_interface.h"

char* era_usb_dev;
double era_control_freq;

thread_t control_thread;
int carmen_era_quit = 0;

void carmen_era_read_parameters(int argc, char **argv) {
  int num_params;
  
  carmen_param_t param_list[] = {
    {"era", "usb_dev", CARMEN_PARAM_STRING, &era_usb_dev, 0, NULL},
    {"era", "control_freq", CARMEN_PARAM_DOUBLE, &era_control_freq, 0, NULL}
  };
  
  num_params = sizeof(param_list)/sizeof(param_list[0]);
  carmen_param_install_params(argc, argv, param_list, num_params);
}

void carmen_era_signaled(int signal) {
  if (signal == SIGINT)
    carmen_era_quit = 1;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s FILE\n", argv[0]);
    return -1;
  }
  const char* file = argv[1];
  carmen_era_read_parameters(argc, argv);

  int result;
  thread_mutex_t mutex;
  era_arm_t arm;
  era_trajectory_t trajectory;
  thread_mutex_init(&mutex);

  config_t can_config;
  config_init(&can_config);
  config_set_string(&can_config, "usb-dev", era_usb_dev);

  can_device_p can_dev = malloc(sizeof(can_device_t));
  can_init(can_dev, &can_config);

  config_destroy(&can_config);
    
  era_config_t era_config;
  era_config_init(&era_config);

  era_init(&arm, can_dev, &era_config);

  era_config_destroy(&era_config);

  if ((result = era_trajectory_read(file, &trajectory)) < 0) {
    fprintf(stderr, "%s\n", era_trajectory_errors[-result]);
    return -1;
  }

  signal(SIGINT, carmen_era_signaled);

  if (era_open(&arm))
    return -1;
  if (!(result = era_control_closed_loop_start(&control_thread, &arm, 
    &mutex, &trajectory, era_control_freq)))
    thread_wait_exit(&control_thread);
  else
    fprintf(stderr, "%s\n", era_control_closed_loop_errors[result]);
  era_close(&arm);

  era_destroy(&arm);
  thread_mutex_destroy(&mutex);
  return 0;






/*  era_motors_init(argv[1]);

  era_arm_configuration_t* trajectory;
  double* timestamps;

  carmen_ipc_initialize( 1, argv );
  carmen_era_define_arm_config_message();
  if ( argc == 3 ) {
    fprintf( stdout, "Execution mode...\n" );
    int result = era_read_arm_trajectory(argv[2], &trajectory, &timestamps);
    if (result > 0) {
      era_sensors_start(send_message, 20.0);

      result = era_move_trajectory(trajectory, timestamps, result);
      era_sensors_exit();

      free(trajectory);
      free(timestamps);
    }
    if (result < 0) era_print_error(stdout, result);
  } else if ( argc == 2 ) {
    fprintf( stdout, "Monitoring mode...\n" );
    era_sensors_start(send_message, 20.0);
    era_thread_wait_exit(&era_sensors_thread);
  }

  era_motors_close();
  return 0;*/
}
