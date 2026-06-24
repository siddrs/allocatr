CC := g++
CFLAGS := -Wall -Wextra -g
BUILD_DIR := ./build

.PHONY: clean all run

all: main

main: main.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $(BUILD_DIR)/$^

main.o: main.cpp
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/$@ $^

clean:
	@echo "Removing build files..."
	rm -rf $(BUILD_DIR)/*

run:
	@./build/main
