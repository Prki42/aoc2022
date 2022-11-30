#pragma once

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

static char *read_input(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (!file) {
        printf("[ERROR] File %s not found\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(length + 1);

    size_t read = length > 0 ? fread(buffer, 1, length, file) : 0;
    if (read != length) {
        free(buffer);
        printf("[ERROR] Failed to read file\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);

    buffer[length] = '\0';

    return buffer;
}

#ifdef AOC_SINGLE_DAY

#define AOC_MAIN(day) \
    int main() { \
        const char *input = read_input("./input.txt"); \
        printf("Part 1: %d\n", part1(input)); \
        printf("Part 2: %d\n", part2(input)); \
        return EXIT_SUCCESS; \
    } \

#else

#define AOC_MAIN(day) \
    void day(char *input) { \
        printf("Part 1\n"); \
        printf("Part 2\n"); \
    } \

#endif
