#include<stdlib.h>
#include<stdio.h>

#include "day01/input.h"

void day01(const char *input);

#define RUN(day) \
    printf("\n" #day "\n"); \
    day(day##_input); \

int main() {
    RUN(day01);

    return EXIT_SUCCESS;
}
