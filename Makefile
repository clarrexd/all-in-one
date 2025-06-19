CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 \
           -Isrc/headers \
           -Isrc/core

SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core
CMD_DIR = $(SRC_DIR)/commands
BUILD_DIR = build
TARGET = all-in-one

SOURCES = $(SRC_DIR)/main.cpp \
          $(CORE_DIR)/CommandHandler.cpp \
          $(wildcard $(CMD_DIR)/*.cpp)

OBJECTS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Default target (build)
all: build

# Build / Compile targets
build compile: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Pattern rule for compiling .cpp files to .o files in the build directory
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