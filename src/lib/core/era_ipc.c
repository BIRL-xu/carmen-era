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

#include "era_ipc.h"

int carmen_era_ipc_initialize(int argc, char *argv[]) {
  IPC_RETURN_TYPE err;

  carmen_ipc_initialize(argc, argv);
  carmen_param_check_version(argv[0]);

  err = IPC_defineMsg(CARMEN_ERA_JOINT_STATE_MESSAGE_NAME, IPC_VARIABLE_LENGTH,
    CARMEN_ERA_JOINT_STATE_MESSAGE_FMT);
  carmen_test_ipc_exit(err, "Could not define message",
    CARMEN_ERA_JOINT_STATE_MESSAGE_NAME);

  err = IPC_defineMsg(CARMEN_ERA_VELOCITY_STATE_MESSAGE_NAME, 
    IPC_VARIABLE_LENGTH, CARMEN_ERA_VELOCITY_STATE_MESSAGE_FMT);
  carmen_test_ipc_exit(err, "Could not define message",
    CARMEN_ERA_VELOCITY_STATE_MESSAGE_NAME);

  err = IPC_defineMsg(CARMEN_ERA_JOINT_CMD_MESSAGE_NAME, IPC_VARIABLE_LENGTH, 
    CARMEN_ERA_JOINT_CMD_MESSAGE_FMT);
  carmen_test_ipc_exit(err, "Could not define message",
    CARMEN_ERA_JOINT_CMD_MESSAGE_NAME);

  err = IPC_defineMsg(CARMEN_ERA_STOP_MESSAGE_NAME, IPC_VARIABLE_LENGTH, 
    CARMEN_ERA_STOP_MESSAGE_FMT);
  carmen_test_ipc_exit(err, "Could not define message",
    CARMEN_ERA_STOP_MESSAGE_NAME);

  return 0;
}
