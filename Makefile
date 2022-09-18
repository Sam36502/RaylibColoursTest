CURR_DIR := $(shell pwd)
SRC_DIR := $(CURR_DIR)/src
BUILD_DIR := $(CURR_DIR)/dist
EXE_NAME := colours

.PHONY: help

help: ## Lists all the commands with a basic description of what they do
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

build:
	cc -l raylib -o $(BUILD_DIR)/$(EXE_NAME) $(SRC_DIR)/colours.c
