include $(CARMEN_HOME)/src/Makefile.conf

CFLAGS +=
IFLAGS += -I../../ -I../../drivers/vanilla/epos -I../../drivers/vanilla/can \
	-I../../drivers/vanilla/cpc-usb -I../../drivers/vanilla/can-cpc \
	-I../../posix/config -I../../posix/timer -I../../posix/thread \
	-I../../posix/spline
LFLAGS += -L../../control -lera-control -lera_interface -lera_params \
	-lipc -lglobal -lparam_interface

MODULE_NAME = ERA
MODULE_COMMENT = Embedded Robot Arm control module

SOURCES = era_interface.c era_params.c era_ipc.c era.c
PUBLIC_INCLUDES = era_interface.h era_params.h era_messages.h
PUBLIC_LIBRARIES = libera_interface.a libera_params.a
PUBLIC_BINARIES = era

TARGETS = libera_interface.a libera_params.a era

all: 

libera_interface.a: era_interface.o

libera_params.a: era_params.o

era: era_ipc.o era.o

include $(CARMEN_HOME)/src/Makefile.rules
