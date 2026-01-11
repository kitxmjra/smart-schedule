# SMART-SCHEDULE MAKEFILE (WINDOWS VERSION)
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
TARGET = smart-schedule.exe

# Windows paths with forward slashes (or escaped backslashes)
C_SOURCES = src-c/main.c \
            src-c/time.c \
            src-c/lesson.c

C_HEADERS = src-c/time.h \
            src-c/lesson.h

# Object files (same directory as sources for simplicity)
C_OBJECTS = $(C_SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Build the program
$(TARGET): $(C_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(C_OBJECTS)
	@echo  Build complete: $(TARGET)

# Compile .c to .o
src-c/%.o: src-c/%.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Alternative: compile all in one directory (simpler for Windows)
simple:
	$(CC) $(CFLAGS) -o $(TARGET) $(C_SOURCES)
	@echo  Simple build complete

# Check what files actually exist
check:
	@echo === Project Structure Check ===
	@echo Current directory:
	@cd
	@echo.
	@echo Files in src-c:
	@dir src-c /B 2>nul || echo Directory src-c not found
	@echo.
	@echo Looking for .c files:
	@dir src-c\*.c 2>nul || echo No .c files found
	@echo.
	@echo Looking for .h files:
	@dir src-c\*.h 2>nul || echo No .h files found

# Run the program
run: $(TARGET)
	$(TARGET)

# Clean build files
clean:
	del /Q $(TARGET) src-c\*.o 2>nul
	@echo  Cleaned build files

# Help
help:
	@echo Available commands:
	@echo   make        - Build the project
	@echo   make simple - Simple one-step build
	@echo   make run    - Build and run
	@echo   make clean  - Remove compiled files
	@echo   make check  - Check project structure
	@echo   make help   - Show this help

.PHONY: all clean run check help simple
