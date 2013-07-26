cmake_minimum_required(VERSION 2.6)

include(ReMake)

remake_project(
  carmen-era
  VERSION 0.1
  RELEASE alpha
  SUMMARY "CARMEN modules for the Embedded Robot Arm (ERA)."
  AUTHOR "Ralf Kaestner"
  CONTACT "ralf.kaestner@gmail.com"
  HOME "http://github.com/kralf/carmen-era"
  LICENSE "GNU Lesser General Public License (LGPL)"
  INSTALL /usr
  PREFIX carmen-
)

remake_pack_deb(
  DEPENDS carmen-interface era-libs tulibs
)
remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "development headers"
  DEPENDS carmen-era carmen-interface-dev era-libs-dev
)

remake_distribute_deb(
  DISTRIBUTION lucid
  SECTION libs
  UPLOAD ppa:kralf/asl
  DEPENDS carmen-interface-dev era-libs-dev tulibs-dev remake
    pkg-config doxygen
  PASS CMAKE_BUILD_TYPE CARMEN_ERA_GIT_REVISION
)
remake_distribute_deb(
  DISTRIBUTION precise
  SECTION libs
  UPLOAD ppa:kralf/asl
  DEPENDS carmen-interface-dev era-libs-dev tulibs-dev remake
    pkg-config doxygen
  PASS CMAKE_BUILD_TYPE CARMEN_ERA_GIT_REVISION
)
