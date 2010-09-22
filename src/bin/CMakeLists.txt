remake_include(../lib/*)

remake_add_executables(
  LINK era_core era_interface era_params ${ERA_LIBRARY}
)
