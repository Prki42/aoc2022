SOURCES_ALL = $(wildcard shared/*.c day*/solution.c)
SHARED_SOURCES = $(wildcard shared/*.c)

CC = gcc
OPT = -02
CFLAGS = -lm -Wall -Wextra $(OPTS)
#CFLAGS = -lm -Wall -Werror  $(OPTS)

all: build

.PHONY: build
build:
	$(CC) $(CFLAGS) -o bin/aoc2022 $(SOURCES_ALL) aoc2022.c

solve/%:
	$(CC) -D AOC_SINGLE_DAY $(CFLAGS) -o bin/day$*/solution $(SHARED_SOUCES) day$*/solution.c
	cp day$*/input.txt bin/day$*/input.txt
	cd bin/day$*/ && ./solution
