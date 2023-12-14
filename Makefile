CC = gcc
CFLAGS = -Wall -Wextra

all: helper

helper: helper.c
	$(CC) $(CFLAGS) -o helper helper.c

clean:
	rm -f helper