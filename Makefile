CC=clang

.PHONY: all
all: build
build:
	$(CC) -lm $(CFLAGS) Snake.c