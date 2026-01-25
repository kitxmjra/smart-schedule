# ============================================
# Makefile for Smart Schedule Project (Linux)
# ============================================

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
TARGET = smart-schedule

# File paths
SRC_DIR = src-c
C_SOURCES = $(SRC_DIR)/main.c \
            $(SRC_DIR)/time.c \
            $(SRC_DIR)/lesson.c \
            $(SRC_DIR)/day_schedule.c

C_HEADERS = $(SRC_DIR)/time.h \
            $(SRC_DIR)/lesson.h \
            $(SRC_DIR)/day_schedule.h

# Object files
OBJ_DIR = obj
C_OBJECTS = $(C_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ============================================
# Main targets
# ============================================

.PHONY: all clean run help

# Default target
all: directories $(TARGET)

# Create obj directory
directories:
	@mkdir -p $(OBJ_DIR)

# Link the program
$(TARGET): $(C_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(C_OBJECTS)
	@echo "Build complete: $(TARGET)"

# Compile .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# ============================================
# Utility targets
# ============================================

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(TARGET)
	rm -rf $(OBJ_DIR)

# Help message
help:
	@echo "Available commands:"
	@echo "  make       - Build the project"
	@echo "  make run   - Build and run"
	@echo "  make clean - Remove compiled files"
	@echo "  make help  - Show this help"
