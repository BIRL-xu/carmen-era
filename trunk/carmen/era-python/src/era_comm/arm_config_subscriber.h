#ifndef ARM_CONFIG_SUBSCRIBER_H
#define ARM_CONFIG_SUBSCRIBER_H

#include "subscriber.h"
#include <era_interface.h>

class ArmConfigSubscriber : public Subscriber, public carmen_era_arm_config_t
{
public:
  ArmConfigSubscriber();
  virtual bool changed();
private:
  double _lastTimestamp;
};

#endif /*ARM_CONFIG_SUBSCRIBER_H*/
