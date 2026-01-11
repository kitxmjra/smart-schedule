# =================================
# SMART-SCHEDULE MAKEFILE
# =================================

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
TARGET = smart-schedule

# Source and Header Files (Update these to match your actual filenames)
C_SOURCES = src-c/main.c \
            src-c/Time.c \
            src-c/Lesson.c \
            src-c/DaySchedule.c

C_HEADERS = src-c/Time.h \
            src-c/Lesson.h \
            src-c/DaySchedule.h

# Automatically generate object file names
C_OBJECTS = $(C_SOURCES:.c=.o)

# =================================
# BUILD TARGETS
# =================================

# Default target: build the C version
all: $(TARGET)

# Main linking target
$(TARGET): $(C_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(C_OBJECTS)
	@echo "✅ Build complete: ./$(TARGET)"

# Rule to compile any .c file in src-c/
src-c/%.o: src-c/%.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# =================================
# UTILITY TARGETS
# =================================

# Build and run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) src-c/*.o
	@echo "🧹 Cleaned build files"

# Check project structure
check:
	@echo "=== Project Structure Check ==="
	@echo "C Source Files:"
	@ls -la src-c/*.c 2>/dev/null || echo "No .c files found in src-c/"
	@echo "Header Files:"
	@ls -la src-c/*.h 2>/dev/null || echo "No .h files found in src-c/"

# Display help
help:
	@echo "Available commands:"
	@echo "  make        - Build the project (default)"
	@echo "  make run    - Build and run the program"
	@echo "  make clean  - Remove all compiled files"
	@echo "  make check  - Verify project file structure"
	@echo "  make help   - Show this help message"

# Phony targets (not actual files)
.PHONY: all clean run check help
