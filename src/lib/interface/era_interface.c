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

#include <carmen/global.h>

#include "era_interface.h"

void carmen_era_subscribe_joint_state_message(carmen_era_joint_state_message* 
  joint_state, carmen_handler_t handler, carmen_subscribe_t subscribe_how) {
  carmen_subscribe_message(CARMEN_ERA_JOINT_STATE_MESSAGE_NAME, 
    CARMEN_ERA_JOINT_STATE_MESSAGE_FMT, joint_state, 
    sizeof(carmen_era_joint_state_message), handler, subscribe_how);
}

void carmen_era_unsubscribe_joint_state_message(carmen_handler_t handler) {
  carmen_unsubscribe_message(CARMEN_ERA_JOINT_STATE_MESSAGE_NAME, handler);
}

void carmen_era_publish_joint_state_message(double shoulder_yaw, double 
  shoulder_roll, double shoulder_pitch, double elbow_pitch, double tool_roll, 
  double tool_opening, double timestamp) {
  carmen_era_joint_state_message message;
  IPC_RETURN_TYPE err;

  message.shoulder_yaw = shoulder_yaw;
  message.shoulder_roll = shoulder_roll;
  message.shoulder_pitch = shoulder_pitch;
  message.elbow_pitch = elbow_pitch;
  message.tool_roll = tool_roll;
  message.tool_opening = tool_opening;

  message.timestamp = timestamp;
  message.host = carmen_get_host();

  err = IPC_publishData(CARMEN_ERA_JOINT_STATE_MESSAGE_NAME, &message);
  carmen_test_ipc_exit(err, "Could not publish",
    CARMEN_ERA_JOINT_STATE_MESSAGE_NAME);
}


void carmen_era_subscribe_velocity_state_message(
  carmen_era_velocity_state_message* vel_state, carmen_handler_t handler, 
  carmen_subscribe_t subscribe_how) {
  carmen_subscribe_message(CARMEN_ERA_VELOCITY_STATE_MESSAGE_NAME, 
    CARMEN_ERA_VELOCITY_STATE_MESSAGE_FMT, vel_state, 
    sizeof(carmen_era_velocity_state_message), handler, subscribe_how);
}

void carmen_era_unsubscribe_velocity_state_message(carmen_handler_t handler) {
  carmen_unsubscribe_message(CARMEN_ERA_VELOCITY_STATE_MESSAGE_NAME, handler);
}

void carmen_era_publish_velocity_state_message(double shoulder_yaw, double 
  shoulder_roll, double shoulder_pitch, double elbow_pitch, double tool_roll,
  double tool_opening, double timestamp) {
  carmen_era_velocity_state_message message;
  IPC_RETURN_TYPE err;

  message.shoulder_yaw = shoulder_yaw;
  message.shoulder_roll = shoulder_roll;
  message.shoulder_pitch = shoulder_pitch;
  message.elbow_pitch = elbow_pitch;
  message.tool_roll = tool_roll;
  message.tool_opening = tool_opening;

  message.timestamp = timestamp;
  message.host = carmen_get_host();

  err = IPC_publishData(CARMEN_ERA_VELOCITY_STATE_MESSAGE_NAME, &message);
  carmen_test_ipc_exit(err, "Could not publish",
    CARMEN_ERA_VELOCITY_STATE_MESSAGE_NAME);
}


void carmen_era_subscribe_joint_cmd_message(carmen_era_joint_cmd_message* 
  joint_cmd, carmen_handler_t handler, carmen_subscribe_t subscribe_how) {
  carmen_subscribe_message(CARMEN_ERA_JOINT_CMD_MESSAGE_NAME, 
    CARMEN_ERA_JOINT_CMD_MESSAGE_FMT, joint_cmd, 
    sizeof(carmen_era_joint_cmd_message), handler, subscribe_how);
}

void carmen_era_unsubscribe_joint_cmd_message(carmen_handler_t handler) {
  carmen_unsubscribe_message(CARMEN_ERA_JOINT_CMD_MESSAGE_NAME, handler);
}

void carmen_era_publish_joint_cmd_message(double shoulder_yaw, double 
  shoulder_roll, double shoulder_pitch, double elbow_pitch, double tool_roll, 
  double tool_opening, double vel_factor, double timestamp) {
  carmen_era_joint_cmd_message message;
  IPC_RETURN_TYPE err;

  message.shoulder_yaw = shoulder_yaw;
  message.shoulder_roll = shoulder_roll;
  message.shoulder_pitch = shoulder_pitch;
  message.elbow_pitch = elbow_pitch;
  message.tool_roll = tool_roll;
  message.tool_opening = tool_opening;

  message.vel_factor = vel_factor;

  message.timestamp = timestamp;
  message.host = carmen_get_host();

  err = IPC_publishData(CARMEN_ERA_JOINT_CMD_MESSAGE_NAME, &message);
  carmen_test_ipc_exit(err, "Could not publish",
    CARMEN_ERA_JOINT_CMD_MESSAGE_NAME);
}


void carmen_era_subscribe_stop_message(carmen_era_stop_message* stop, 
  carmen_handler_t handler, carmen_subscribe_t subscribe_how) {
  carmen_subscribe_message(CARMEN_ERA_STOP_MESSAGE_NAME, 
    CARMEN_ERA_STOP_MESSAGE_FMT, stop, sizeof(carmen_era_stop_message), 
    handler, subscribe_how);
}

void carmen_era_unsubscribe_stop_message(carmen_handler_t handler) {
  carmen_unsubscribe_message(CARMEN_ERA_STOP_MESSAGE_NAME, handler);
}

void carmen_era_publish_stop_message(double timestamp) {
  carmen_era_stop_message message;
  IPC_RETURN_TYPE err;

  message.timestamp = timestamp;
  message.host = carmen_get_host();

  err = IPC_publishData(CARMEN_ERA_STOP_MESSAGE_NAME, &message);
  carmen_test_ipc_exit(err, "Could not publish",
    CARMEN_ERA_STOP_MESSAGE_NAME);
}
