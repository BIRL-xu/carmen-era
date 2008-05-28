project( carmen-era )

set( PACKAGE_NAME ${PROJECT_NAME} )
set( PACKAGE_VERSION 0.0.1 )
set( PACKAGE_RELEASE 0 )
set( PACKAGE_MAINTAINER_NAME "Dizan Vasquez" )
set( PACKAGE_MAINTAINER_EMAIL "vasquez@mavt.ethz.ch" )
set( PACKAGE_DESCRIPTION_SUMMARY "BlueBotics ERA-5/1 CARMEN interfaces" )
set( PACKAGE_DESCRIPTION "Carmen interfaces for controlling and monitoring bluebotics' ERA-5/1 robotic arm" )
set( PACKAGE_DEPENDS )

include( SimpleCMake )
sm_configure_project()
