cc = gcc
CFLAGS = -Wall -Wextra

ALL = mypipe.c create_pipe.c

OBJ = $(ALL:.c=.o)

TARGET = mypipe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)