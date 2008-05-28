#include "arm_config_publisher.h"

using namespace std;

//------------------------------------------------------------------------------

ArmConfigPublisher::ArmConfigPublisher()
{
  carmen_era_define_arm_config_message();
}

//------------------------------------------------------------------------------

void
ArmConfigPublisher::send()
{
  carmen_era_publish_arm_config_message( this );
}
