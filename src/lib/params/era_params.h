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

#ifndef CARMEN_ERA_PARAMS_H
#define CARMEN_ERA_PARAMS_H

/** @addtogroup era **/
// @{

/** \brief Definition of the parameters of this module.
  * This file specifies the parameters of this module.
  **/

#ifdef __cplusplus
extern "C" {
#endif

#include <era-libs/config/config.h>

/** \brief Read parameters from parameter daemon into a configuration object
 */
int carmen_era_params_read(
  int argc, 
  char *argv[],
  config_p  can_config,
  era_config_p era_config,
  double* control_freq);

#ifdef __cplusplus
}
#endif

#endif

// @}
