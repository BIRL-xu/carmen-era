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

#ifndef _CARMEN_ERA_MESSAGES_H
#define _CARMEN_ERA_MESSAGES_H

/** @addtogroup era **/
// @{

/** \brief BlueBotics ERA-5/1 CARMEN messages
  * This file specifies the messages for the BlueBotics ERA-5/1.
  **/

#ifdef __cplusplus
extern "C" {
#endif

/** \brief Joint configuration space state message 
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

#ifdef __cplusplus
}
#endif

#endif

// @}
