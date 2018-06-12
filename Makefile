# This stub makefile for a Kaleidoscope plugin pulls in 
# all targets from the Kaleidoscope-Plugin library

LOCAL_CFLAGS := -DKALEIDOSCOPE_ENABLE_V1_PLUGIN_API=0
export LOCAL_CFLAGS

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
SKETCHBOOK_DIR ?= $(HOME)/Documents/Arduino
PACKAGE_DIR ?= $(HOME)/Library/Arduino15
else
SKETCHBOOK_DIR ?= $(HOME)/Arduino
PACKAGE_DIR ?= $(HOME)/.arduino15
endif

BOARD_HARDWARE_PATH ?= $(SKETCHBOOK_DIR)/hardware
KALEIDOSCOPE_PLUGIN_MAKEFILE_DIR ?= keyboardio/avr/build-tools/makefiles/

include $(BOARD_HARDWARE_PATH)/$(KALEIDOSCOPE_PLUGIN_MAKEFILE_DIR)/rules.mk
