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

#ifndef _CARMEN_ERA_INTERFACE_H
#define _CARMEN_ERA_INTERFACE_H

/** @addtogroup era **/
// @{

/** \brief BlueBotics ERA-5/1 CARMEN interfaces
  * This file specifies the interface functions for the BlueBotics ERA-5/1.
  **/

#ifdef __cplusplus
extern "C" {
#endif

#include <base/era.h>

#include <carmen/carmen.h>

#include "era_messages.h"

/** \brief Subscribes to joint state configuration reporting messages
 */
void carmen_era_subscribe_joint_state_message(
  carmen_era_joint_state_message* joint_state,
  carmen_handler_t handler,
  carmen_subscribe_t subscribe_how);

/** \brief Unsubscribes from joint state configuration reporting messages
 */
void carmen_era_unsubscribe_joint_state_message(
  carmen_handler_t handler);

/** \brief Publish joint state configuration reporting messages
 */
void carmen_era_publish_joint_state(
  era_joint_state_p joint_state,
  double timestamp);

#ifdef __cplusplus
}
#endif

#endif

// @}
