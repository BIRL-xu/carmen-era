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
#include <carmen/param_interface.h>

#include <libcan/can_cpc.h>

#include "era_params.h"

char* era_can_usb_dev;

double era_control_freq;

int carmen_era_params_read(int argc, char *argv[], config_p can_config, 
  era_config_p era_config, double* control_freq) {
  int num_params;
  
  carmen_param_t param_list[] = {
    {"era", "usb_dev", CARMEN_PARAM_STRING, &era_can_usb_dev, 0, NULL},

    {"era", "control_freq", CARMEN_PARAM_DOUBLE, &era_control_freq, 0, NULL}
  };
  
  num_params = sizeof(param_list)/sizeof(param_list[0]);
  carmen_param_install_params(argc, argv, param_list, num_params);

  config_set_string(can_config, CAN_CPC_PARAMETER_DEVICE, era_can_usb_dev);

  if (control_freq)
    *control_freq = era_control_freq;

  return num_params;
}
