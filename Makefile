CFLAGS = -o2 -Wall
LDFLAGS = -lwalkingdriver
vpath %.c src/

all: main

main: main.c

.PHONY: all
