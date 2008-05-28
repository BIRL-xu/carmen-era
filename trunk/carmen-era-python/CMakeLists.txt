project( carmen-era-python )

set( PACKAGE_NAME ${PROJECT_NAME} )
set( PACKAGE_VERSION 0.0.1 )
set( PACKAGE_RELEASE 0 )
set( PACKAGE_MAINTAINER_NAME "Dizan Vasquez" )
set( PACKAGE_MAINTAINER_EMAIL "vasquez@mavt.ethz.ch" )
set( PACKAGE_DESCRIPTION_SUMMARY "Python bindings for carmen-era" )
set( PACKAGE_DESCRIPTION "Python bindings for Bluebotics' ERA carmen controllers." )
set( PACKAGE_DEPENDS "carmen-era (>= 0.0.1)")

include( SimpleCMake )
sm_configure_project()
