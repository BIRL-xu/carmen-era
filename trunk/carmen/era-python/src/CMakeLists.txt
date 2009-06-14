include( SwigPython )

sm_cpp_include_dir( CARMEN carmen )
sm_cpp_include_dir( CARMEN_ERA carmen-era )

set( CARMEN_LIBRARY_PATH /usr/ CACHE PATH "Carmen libraries" )
link_directories( ${CARMEN_LIBRARY_PATH} )

add_library(
  era_comm SHARED
  era_comm/era_comm.cpp
  era_comm/communications_base.cpp
  era_comm/arm_config_publisher.cpp
  era_comm/arm_config_subscriber.cpp
)

target_link_libraries(
  era_comm
  carmen-era
  z
  global
  ipc
)

sm_cpp_install( era_comm )
swig_python( era_comm era_comm )
