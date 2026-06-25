# TODO:: wildcards; clean this mess up

CC := g++
CFLAGS := -Wall -Wextra -g
BUILD_DIR := ./build
SRC_DIR := ./src
INC_DIR := ./include

.PHONY: clean all run

all: $(BUILD_DIR)/app

$(BUILD_DIR)/app: $(BUILD_DIR)/main.o $(BUILD_DIR)/freelist.o $(BUILD_DIR)/allocatr.o
	@$(CC) $(CFLAGS) -Iinclude $^ -o $@ 

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	@$(CC) $(CFLAGS) -Iinclude -c $^ -o $@ 

$(BUILD_DIR)/freelist.o: $(SRC_DIR)/freelist.cpp
	@$(CC) $(CFLAGS) -Iinclude -c $^ -o $@

$(BUILD_DIR)/allocatr.o: $(SRC_DIR)/allocatr.cpp
	@$(CC) $(CFLAGS) -Iinclude -c $^ -o $@


clean:
	@echo "Removing build files..."
	rm -rf $(BUILD_DIR)/*

run: $(BUILD_DIR)/app
	@$^


