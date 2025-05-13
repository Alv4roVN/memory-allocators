CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
OBJ = align.o lalloc.o test_lalloc.o
TARGET = test_lalloc

all: $(TARGET) clean-obj

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean-obj:
	@rm -f $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
