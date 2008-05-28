/*      Header-file for
 *      BlueBotics ERA-5/1 CARMEN messages
 *
 *      Ralf Kaestner    ralf.kaestner@gmail.com
 *      Last change:     28.5.2008
 */

#ifndef _CARMEN_ERA_MESSAGES_H
#define _CARMEN_ERA_MESSAGES_H

/** \file
  * \brief BlueBotics ERA-5/1 CARMEN messages
  *
  * This file specifies the messages for the BlueBotics ERA-5/1.
  **/

#ifdef __cplusplus
extern "C" {
#endif

/** \brief Arm configuration message */
typedef struct {
  double shoulder_yaw;    //!< The shoulder's yaw angle [rad], denoted theta1.
  double shoulder_roll;   //!< The shoulder's roll angle [rad], denoted theta2.
  double shoulder_pitch;  //!< The shoulder's pitch angle [rad], denoted theta3.
  double ellbow_pitch;    //!< The ellbow's pitch angle [rad], denoted theta4.
  double tool_roll;       //!< The tool's roll angle [rad], denoted theta6.
  double tool_opening;    //!< The tool's opening angle [rad].
  double timestamp;       //!< The message timestamp in [s].
  char *host;             //!< The name of the sending host.
} carmen_era_arm_config_t;

#define CARMEN_ERA_ARM_CONFIG_NAME  "era_arm_config"
#define CARMEN_ERA_ARM_CONFIG_FMT   "{double,double,double,double,double,double,double,string}"

#ifdef __cplusplus
}
#endif

#endif
