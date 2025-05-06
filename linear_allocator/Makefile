# Compiler and Flags
CC = gcc
CFLAGS = -Wall -g -c  # Compilation flags (debugging and warnings)
AR = ar  # Archive tool to create the static library

# Library and Object File Names
LIBRARY = liblalloc.a  # Static library name
OBJ = align.o lalloc.o  # Object files

# Default target (build the library)
$(LIBRARY): $(OBJ)
	$(AR) rcs $(LIBRARY) $(OBJ)  # Create the static library

# Rule to compile align.c
align.o: align.c align.h
	$(CC) $(CFLAGS) align.c -o align.o

# Rule to compile lalloc.c
lalloc.o: lalloc.c align.h
	$(CC) $(CFLAGS) lalloc.c -o lalloc.o

# Clean up generated files
clean:
	rm -f $(OBJ) $(LIBRARY)

