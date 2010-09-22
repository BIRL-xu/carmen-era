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

#ifndef CARMEN_ERA_INTERFACE_H
#define CARMEN_ERA_INTERFACE_H

/** @addtogroup era **/
// @{

/** \brief BlueBotics ERA-5/1 CARMEN interfaces
  * This file specifies the interface functions for the BlueBotics ERA-5/1.
  **/

#ifdef __cplusplus
extern "C" {
#endif

#include <carmen/carmen.h>

#include "era_messages.h"

/** \brief Subscribes to joint state messages
 */
void carmen_era_subscribe_joint_state_message(
  carmen_era_joint_state_message* joint_state,
  carmen_handler_t handler,
  carmen_subscribe_t subscribe_how);

/** \brief Unsubscribes from joint state messages
 */
void carmen_era_unsubscribe_joint_state_message(
  carmen_handler_t handler);

/** \brief Publish joint state messages
 */
void carmen_era_publish_joint_state_message(
  double shoulder_yaw,
  double shoulder_roll,
  double shoulder_pitch,
  double elbow_pitch,
  double tool_roll,
  double tool_opening,
  double timestamp);


/** \brief Subscribes to velocity state messages
 */
void carmen_era_subscribe_velocity_state_message(
  carmen_era_velocity_state_message* vel_state,
  carmen_handler_t handler,
  carmen_subscribe_t subscribe_how);

/** \brief Unsubscribes from velocity state messages
 */
void carmen_era_unsubscribe_velocity_state_message(
  carmen_handler_t handler);

/** \brief Publish velocity state messages
 */
void carmen_era_publish_velocity_state_message(
  double shoulder_yaw,
  double shoulder_roll,
  double shoulder_pitch,
  double elbow_pitch,
  double tool_roll,
  double tool_opening,
  double timestamp);


/** \brief Subscribes to joint command messages
 */
void carmen_era_subscribe_joint_cmd_message(
  carmen_era_joint_cmd_message* joint_cmd,
  carmen_handler_t handler,
  carmen_subscribe_t subscribe_how);

/** \brief Unsubscribes from joint command messages
 */
void carmen_era_unsubscribe_joint_cmd_message(
  carmen_handler_t handler);

/** \brief Publish joint command messages
 */
void carmen_era_publish_joint_cmd_message(
  double shoulder_yaw,
  double shoulder_roll,
  double shoulder_pitch,
  double elbow_pitch,
  double tool_roll,
  double tool_opening,
  double vel_factor,
  double timestamp);


/** \brief Subscribes to stop messages
 */
void carmen_era_subscribe_stop_message(
  carmen_era_stop_message* stop,
  carmen_handler_t handler,
  carmen_subscribe_t subscribe_how);

/** \brief Unsubscribes from stop messages
 */
void carmen_era_unsubscribe_stop_message(
  carmen_handler_t handler);

/** \brief Publish stop messages
 */
void carmen_era_publish_stop_message(
  double timestamp);

#ifdef __cplusplus
}
#endif

#endif

// @}
