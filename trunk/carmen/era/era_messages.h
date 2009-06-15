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

#ifndef CARMEN_ERA_MESSAGES_H
#define CARMEN_ERA_MESSAGES_H

/** @addtogroup era **/
// @{

/** \brief BlueBotics ERA-5/1 CARMEN messages
  * This file specifies the messages for the BlueBotics ERA-5/1.
  **/

#ifdef __cplusplus
extern "C" {
#endif

/** \brief Joint space state message 
  */
typedef struct {
  double shoulder_yaw;    //!< The shoulder's yaw angle in [rad].
  double shoulder_roll;   //!< The shoulder's roll angle in [rad].
  double shoulder_pitch;  //!< The shoulder's pitch angle in [rad].
  double elbow_pitch;     //!< The elbow's pitch angle in [rad].
  double tool_roll;       //!< The tool's roll angle in [rad].
  double tool_opening;    //!< The tool's opening angle in [rad].

  double timestamp;       //!< The message timestamp in [s].
  char *host;             //!< The name of the sending host.
} carmen_era_joint_state_message;

#define CARMEN_ERA_JOINT_STATE_MESSAGE_NAME "era_joint_state_message"
#define CARMEN_ERA_JOINT_STATE_MESSAGE_FMT "{double,double,double,double,double,double,double,string}"

/** \brief Velocity space state message 
  */
typedef struct {
  double shoulder_yaw;    //!< The shoulder's yaw velocity in [rad/s].
  double shoulder_roll;   //!< The shoulder's roll velocity in [rad/s].
  double shoulder_pitch;  //!< The shoulder's pitch velocity in [rad/s].
  double elbow_pitch;     //!< The elbow's pitch velocity in [rad/s].
  double tool_roll;       //!< The tool's roll velocity in [rad/s].
  double tool_opening;    //!< The tool's opening velocity in [rad/s].

  double timestamp;       //!< The message timestamp in [s].
  char *host;             //!< The name of the sending host.
} carmen_era_velocity_state_message;

#define CARMEN_ERA_VELOCITY_STATE_MESSAGE_NAME "era_velocity_state_message"
#define CARMEN_ERA_VELOCITY_STATE_MESSAGE_FMT "{double,double,double,double,double,double,double,string}"

/** \brief Joint space command message 
  */
typedef struct {
  double shoulder_yaw;    //!< The shoulder's yaw angle in [rad].
  double shoulder_roll;   //!< The shoulder's roll angle in [rad].
  double shoulder_pitch;  //!< The shoulder's pitch angle in [rad].
  double elbow_pitch;     //!< The elbow's pitch angle in [rad].
  double tool_roll;       //!< The tool's roll angle in [rad].
  double tool_opening;    //!< The tool's opening angle in [rad].

  double vel_factor;      //!< A velocity factor in the range 0 to 1.

  double timestamp;       //!< The message timestamp in [s].
  char *host;             //!< The name of the sending host.
} carmen_era_joint_cmd_message;

#define CARMEN_ERA_JOINT_CMD_MESSAGE_NAME "era_joint_cmd_message"
#define CARMEN_ERA_JOINT_CMD_MESSAGE_FMT "{double,double,double,double,double,double,double,double,string}"

#ifdef __cplusplus
}
#endif

#endif

// @}
