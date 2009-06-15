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

#include <timer.h>
#include <thread.h>

#include <base/era.h>
#include <motors/home.h>
#include <control/sensors.h>

#include "era_params.h"
#include "era_ipc.h"
#include "era_interface.h"

carmen_era_joint_cmd_message carmen_era_joint_cmd;

int carmen_era_quit = 0;

void carmen_era_signaled(int signal) {
  if (signal == SIGINT)
    carmen_era_quit = 1;
}

int carmen_era_connect(era_arm_p arm) {
  int result = -1;

  fprintf(stderr, "Connecting the arm");
  while (!carmen_era_quit) {
    fprintf(stderr, ".");
    fflush(stderr);

    if (!era_open(arm)) {
      fprintf(stderr, "... success.\n");
      result = 0;

      break;
    }

    timer_sleep(1.0);
  }
  if (result)
    fprintf(stderr, "... failed.\n");

  return result;
}

int carmen_era_home(era_arm_p arm) {
  int result = -1;

  fprintf(stderr, "Homing the arm");
  if (!era_security_enable_home(&arm->security, &arm->motors)) {
    if (!era_motors_home_start(&arm->motors, &arm->security)) {
      while (!carmen_era_quit && era_motors_home_wait(&arm->motors, 1.0)) {
        fprintf(stderr, ".");
        fflush(stderr);
      }

      if (!carmen_era_quit) {
        fprintf(stderr, "... done.\n");
        result = 0;
      }
      else
        fprintf(stderr, "... interrupted.\n");

      era_motors_home_stop(&arm->motors);
    }
    era_security_enable(&arm->security, &arm->motors);
  }
  else
    fprintf(stderr, "... security error.\n");

  return result;
}

void carmen_era_sensors_handle(era_joint_state_p joint_state, 
  era_velocity_state_p vel_state, double freq __attribute__ ((unused))) {
  double timestamp = carmen_get_time();

  carmen_era_publish_joint_state(joint_state, timestamp);
  carmen_era_publish_velocity_state(vel_state, timestamp);

  fprintf(stderr, "S");
  fflush(stderr);
}

void carmen_era_joint_cmd_handle(void* joint_cmd) {
  fprintf(stderr, "C");
  fflush(stderr);
}

void carmen_era_wait_commands(era_arm_p arm, double freq) {
  thread_t sensor_thread;
  thread_mutex_t mutex;

  fprintf(stderr, "Now accepting motion commands.\n\n");
  era_control_sensors_start(&sensor_thread, arm, &mutex, 
    carmen_era_sensors_handle, freq);
  carmen_era_subscribe_joint_cmd_message(&carmen_era_joint_cmd,
    carmen_era_joint_cmd_handle, CARMEN_SUBSCRIBE_LATEST);

  while (!carmen_era_quit) timer_sleep(0.1);
  fprintf(stderr, "\n");

  carmen_era_unsubscribe_joint_cmd_message(carmen_era_joint_cmd_handle);
  era_control_sensors_exit(&sensor_thread);
}

int main(int argc, char **argv) {
  config_t can_config;
  era_config_t era_config;
  era_arm_t arm;
  double freq;

  config_init(&can_config);
  era_config_init(&era_config);

  carmen_era_ipc_initialize(argc, argv);
  carmen_era_params_read(argc, argv, &can_config, &era_config, &freq);

  can_device_p can_dev = malloc(sizeof(can_device_t));
  can_init(can_dev, &can_config);
  era_init(&arm, can_dev, &era_config);

  config_destroy(&can_config);
  era_config_destroy(&era_config);

  signal(SIGINT, carmen_era_signaled);

  if (!carmen_era_connect(&arm) /*&& !carmen_era_home(&arm)*/)
    carmen_era_wait_commands(&arm, freq);

  era_close(&arm);
  era_destroy(&arm);
  return 0;
}
