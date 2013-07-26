remake_include(../lib/*)

remake_add_executable(carmen-era era.c PREFIX OFF
  LINK era_core era_interface era_params ${ERA_LIBS_LIBRARIES}
    ${TULIBS_LIBRARIES}
)
