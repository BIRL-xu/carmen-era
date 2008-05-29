sm_cpp_include_dir( CARMEN carmen )
sm_cpp_include_dir( ERA_CONTROLLER era/controller )
sm_cpp_include_dir( ERA_KINEMATICS era/kinematics )

set( CARMEN_LIBRARY_PATH /usr/ CACHE PATH "Carmen libraries" )
link_directories( ${CARMEN_LIBRARY_PATH} )

add_library( carmen-era SHARED carmen-era/era_interface.c )
add_executable( era_trajectory carmen-era/era_trajectory.c )

target_link_libraries(
  carmen-era
  z
  global
  ipc
)

target_link_libraries(
  era_trajectory era-controller carmen-era
)
sm_cpp_install( carmen-era )
