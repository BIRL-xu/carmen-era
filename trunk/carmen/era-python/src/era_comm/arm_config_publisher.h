#ifndef ARM_CONFIG_PUBLISHER
#define ARM_CONFIG_PUBLISHER

#include "publisher.h"
#include <era_interface.h>

class ArmConfigPublisher : public Publisher, public carmen_era_arm_config_t
{
public:
  ArmConfigPublisher();
  virtual void send();
};

#endif /*ARM_CONFIG_PUBLISHER*/
