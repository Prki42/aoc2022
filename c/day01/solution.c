#include "../shared/aoc.h"

struct Result solve(const char* input) {
    struct Result result; 
    size_t len = strlen(input);
    char last = '0';
    char *end;
    int max1, max2, max3;
    max1 = max2 = max3 = 0;
    int sum = 0;
    size_t i = 0;
    while(i < len) {
        if(input[i] == '\n') {
            if(last == '\n') {
                if(sum > max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = sum;
                } else if(sum > max2) {
                    max3 = max2;
                    max2 = sum;
                } else if(sum > max3) {
                    max3 = sum;
                }
                sum = 0;
            }
            last = input[i];
            i++;
        } else {
            sum += (int)strtol(input + i, &end, 10);
            i += end - (input + i);
            last = input[i];
            i++;
        }
    }

    result.part1 = max1;
    result.part2 = max1 + max2 + max3;
    return result;
}

AOC_MAIN(day01);
