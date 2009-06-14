#include "era_messages.h"
#include <carmen/carmen.h>
#include <assert.h>

void
carmen_era_subscribe_arm_config_message(
  carmen_era_arm_config_t *config,
  carmen_handler_t handler,
  carmen_subscribe_t subscribe_how)
{
  carmen_subscribe_message(
    CARMEN_ERA_ARM_CONFIG_NAME,
    CARMEN_ERA_ARM_CONFIG_FMT,
    config,
    sizeof( carmen_era_arm_config_t ),
    handler,
    subscribe_how
  );
}

void
carmen_era_unsubscribe_arm_config_message( carmen_handler_t handler )
{
  carmen_unsubscribe_message( CARMEN_ERA_ARM_CONFIG_NAME, handler );
}

void
carmen_era_define_arm_config_message()
{
  IPC_RETURN_TYPE err;

  err = IPC_defineMsg(
    CARMEN_ERA_ARM_CONFIG_NAME,
    IPC_VARIABLE_LENGTH,
    CARMEN_ERA_ARM_CONFIG_FMT
  );
  carmen_test_ipc_exit( err, "Could not define", CARMEN_ERA_ARM_CONFIG_NAME );
}

void
carmen_era_publish_arm_config_message( carmen_era_arm_config_t* config )
{
  IPC_RETURN_TYPE err;
  err = IPC_publishData( CARMEN_ERA_ARM_CONFIG_NAME, config );
  carmen_test_ipc_exit( err, "Could not publish", CARMEN_ERA_ARM_CONFIG_NAME );
}
