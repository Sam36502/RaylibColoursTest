CURR_DIR := $(shell pwd)
SRC_DIR ?= $(CURR_DIR)/src
BUILD_DIR ?= $(CURR_DIR)/dist
LINUX_DIR ?= $(BUILD_DIR)/lin
WINDOWS_DIR ?= $(BUILD_DIR)/win
EXE_NAME := colours

.PHONY: help build-all build-linux build-windows

help: ## Lists all the commands with a basic description of what they do
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

build-all: build-linux build-windows ## Builds all supported executables

build-linux: ## Builds the executable for linux
	PLATFORM_OS=LINUX cc -l raylib -o $(LINUX_DIR)/$(EXE_NAME) $(SRC_DIR)/*.c

build-windows: ## Builds the executable for windows
	PLATFORM_OS=WINDOWS cc -l raylib -o $(WINDOWS_DIR)/$(EXE_NAME).exe $(SRC_DIR)/*.c
