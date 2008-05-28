#include "arm_config_subscriber.h"

using namespace std;

//------------------------------------------------------------------------------

ArmConfigSubscriber::ArmConfigSubscriber()
  : _lastTimestamp( 0 )
{
  carmen_era_subscribe_arm_config_message( this, NULL, CARMEN_SUBSCRIBE_LATEST );
}

//------------------------------------------------------------------------------

bool
ArmConfigSubscriber::changed()
{
  bool result = _lastTimestamp && _lastTimestamp != timestamp;
  _lastTimestamp = timestamp;
  return result;
}

