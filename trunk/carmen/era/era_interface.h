/*      Header-file for
 *      BlueBotics ERA-5/1 CARMEN messages
 *
 *      Dizan Vasquez    vasquez@mavt.ethz.ch
 *      Last change:     28.5.2008
 */

/** \file
  * \brief BlueBotics ERA-5/1 CARMEN interfaces
  *
  * This file specifies the interface functions for the BlueBotics ERA-5/1.
  **/

#ifndef _CARMEN_ERA_INTERFACE_H
#define _CARMEN_ERA_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <carmen/carmen.h>
#include "era_messages.h"


/**
 * \brief Subscribes to arm configuration reporting messages
 */
void
carmen_era_subscribe_arm_config_message(
  carmen_era_arm_config_t *config,
  carmen_handler_t handler,
  carmen_subscribe_t subscribe_how
);

/**
 * \brief Unsubscribes from arm configuration reporting messages
 */
void
carmen_era_unsubscribe_arm_config_message( carmen_handler_t handler );

/**
 * \brief Defines arm configuration message for publishing
 */
void
carmen_era_define_arm_config_message();

/**
 * \brief Publishes the current arm configuration
 */
void
carmen_era_publish_arm_config_message( carmen_era_arm_config_t* config );


#ifdef __cplusplus
}
#endif

#endif

