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
#include <dynamics/dynamics.h>
#include <motors/position_profile.h>
#include <control/sensors.h>

#include "era_params.h"
#include "era_ipc.h"
#include "era_interface.h"

carmen_era_joint_cmd_message carmen_era_joint_cmd;
carmen_era_stop_message carmen_era_stop;

int carmen_era_quit = 0;

era_arm_t carmen_era_arm;
thread_mutex_t carmen_era_mutex;

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

  carmen_era_publish_joint_state_message(joint_state->shoulder_yaw, 
    joint_state->shoulder_roll, joint_state->shoulder_pitch, 
    joint_state->elbow_pitch, joint_state->tool_roll, 
    joint_state->tool_opening, timestamp);
  carmen_era_publish_velocity_state_message(vel_state->shoulder_yaw, 
    vel_state->shoulder_roll, vel_state->shoulder_pitch, 
    vel_state->elbow_pitch, vel_state->tool_roll, vel_state->tool_opening, 
    timestamp);

  fprintf(stderr, "S");
  fflush(stderr);
}

void carmen_era_joint_cmd_handle(void* joint_cmd) {
  era_joint_state_t start_state;
  era_joint_state_t target_state;
  era_velocity_state_t vel_state;
  era_motors_position_profile_t profile;
  carmen_era_joint_cmd_message* message = joint_cmd;
  int result;

  fprintf(stderr, "C");
  fflush(stderr);

  thread_mutex_lock(&carmen_era_mutex);
  era_motors_position_profile_stop(&carmen_era_arm.motors);
  thread_mutex_unlock(&carmen_era_mutex);

  target_state.shoulder_yaw = message->shoulder_yaw;
  target_state.shoulder_roll = message->shoulder_roll;
  target_state.shoulder_pitch = message->shoulder_pitch;
  target_state.elbow_pitch = message->elbow_pitch;
  target_state.tool_roll = message->tool_roll;
  target_state.tool_opening = message->tool_opening;
  
  if ((result = era_kinematics_limits_test_state(&carmen_era_arm.kin_limits, 
    &target_state))) {
    fprintf(stderr, "\n%s\n", era_kinematics_limits_errors[result]);
    return;
  }
    
  era_get_joint_state(&carmen_era_arm, &start_state);
  era_dynamics_limit_state(&start_state, &target_state, 
    &carmen_era_arm.dyn_limits, message->vel_factor, &vel_state);

  era_motors_position_profile_init(&profile, &target_state, &vel_state,
    &carmen_era_arm.dyn_limits.max_accel, &carmen_era_arm.dyn_limits.min_accel, 
    epos_profile_sinusoidal);

  thread_mutex_lock(&carmen_era_mutex);
  era_motors_position_profile_start(&carmen_era_arm.motors, &profile);
  thread_mutex_unlock(&carmen_era_mutex);
}

void carmen_era_stop_handle(void* joint_cmd) {
  fprintf(stderr, ".");
  fflush(stderr);

  thread_mutex_lock(&carmen_era_mutex);
  era_motors_position_profile_stop(&carmen_era_arm.motors);
  thread_mutex_unlock(&carmen_era_mutex);
}

void carmen_era_wait_commands(era_arm_p arm, double freq) {
  thread_t sensor_thread;

  fprintf(stderr, "Now accepting motion commands.\n\n");
  era_control_sensors_start(&sensor_thread, arm, &carmen_era_mutex, 
    carmen_era_sensors_handle, freq);
  timer_sleep(1.0);
  carmen_era_subscribe_joint_cmd_message(&carmen_era_joint_cmd,
    carmen_era_joint_cmd_handle, CARMEN_SUBSCRIBE_LATEST);
  carmen_era_subscribe_stop_message(&carmen_era_stop, carmen_era_stop_handle, 
    CARMEN_SUBSCRIBE_LATEST);

  while (!carmen_era_quit) carmen_ipc_sleep(0.1);
  fprintf(stderr, "\n");

  carmen_era_unsubscribe_stop_message(carmen_era_stop_handle);
  carmen_era_unsubscribe_joint_cmd_message(carmen_era_joint_cmd_handle);
  era_control_sensors_exit(&sensor_thread);
}

int main(int argc, char **argv) {
  config_t can_config;
  era_config_t era_config;
  double freq;

  config_init(&can_config);
  era_config_init(&era_config);

  carmen_era_ipc_initialize(argc, argv);
  carmen_era_params_read(argc, argv, &can_config, &era_config, &freq);

  can_device_p can_dev = malloc(sizeof(can_device_t));
  can_init(can_dev, &can_config);
  era_init(&carmen_era_arm, can_dev, &era_config);

  config_destroy(&can_config);
  era_config_destroy(&era_config);

  signal(SIGINT, carmen_era_signaled);

  thread_mutex_init(&carmen_era_mutex);
  if (!carmen_era_connect(&carmen_era_arm) && 
    !carmen_era_home(&carmen_era_arm))
    carmen_era_wait_commands(&carmen_era_arm, freq);
  thread_mutex_destroy(&carmen_era_mutex);

  era_close(&carmen_era_arm);
  era_destroy(&carmen_era_arm);
  return 0;
}
