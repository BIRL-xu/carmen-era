sm_cpp_include_dir( CARMEN carmen )

set( CARMEN_LIBRARY_PATH /usr/ CACHE PATH "Carmen libraries" )
link_directories( ${CARMEN_LIBRARY_PATH} )

add_library( carmen-era SHARED carmen-era/era_interface.c )

target_link_libraries(
  carmen-era
  z
  global
  ipc
)

sm_cpp_install( carmen-era )
