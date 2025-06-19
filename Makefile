# Makefile for all-in-one C++ app

CXX = g++
CXXFLAGS = -std=c++17 -Isrc/headers -Wall -Wextra -O2
SRC_DIR = src
CMD_DIR = $(SRC_DIR)/commands
BUILD_DIR = build
TARGET = all-in-one

SOURCES = main.cpp \
          $(SRC_DIR)/CommandHandler.cpp \
          $(wildcard $(CMD_DIR)/*.cpp)

OBJECTS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Default target (build)
all: build

# Build / Compile targets
build compile: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run / Execute targets
run execute: $(TARGET)
	./$(TARGET)

# Clean target
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all build compile run execute clean
