include $(CARMEN_HOME)/src/Makefile.conf

CFLAGS +=
IFLAGS += -I../../ -I../../drivers/vanilla/epos -I../../drivers/vanilla/can \
	-I../../posix/config -I../../posix/thread -I../../posix/spline
LFLAGS += -L../../control -lera-control -lera_interface -lipc -lglobal \
	-lparam_interface

MODULE_NAME = ERA
MODULE_COMMENT = Embedded Robot Arm control module

SOURCES = era_interface.c era_ipc.c era_trajectory.c
PUBLIC_INCLUDES = era_interface.h era_messages.h
PUBLIC_LIBRARIES = libera_interface.a
PUBLIC_BINARIES = era_trajectory

TARGETS = libera_interface.a era_trajectory

all: 

libera_interface.a: era_interface.o

era_trajectory: era_ipc.o era_trajectory.o

include $(CARMEN_HOME)/src/Makefile.rules
