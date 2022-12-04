#include "../shared/aoc.h"
#include <stdlib.h>
#include <string.h>

short value(char x) {
    if (islower(x)) {
        return x - 'a' + 1;
    }
    return x - 'A' + 27;
}

struct Result solve(const char* input) {
    struct Result result;
    const char *end, *start;
    size_t half;
    short *table = (short *)calloc(52, sizeof(short));
    short *table2 = (short *)calloc(52, sizeof(short));
    int sum1, sum2;
    short counter = 0;
    bool found;
    
    sum1 = sum2 = 0;
    
    start = input;
    end = strchr(input, '\n');
    while(end != NULL) {
        end--;
        counter++;
        found = false;
        memset(table, 0, 52*sizeof(short));
        half = (end-start)/2;
        for(size_t i=0; i<half+1; i++) {
            short val = value(start[i]);
            if(table[val-1] == 0) {
                table2[val-1]++;
            }
            table[val-1] = 1;
        }
        for(size_t i=half+1; i<(size_t)(end-start)+1; i++) {
            short val = value(start[i]);
            if(table[val-1] == 0) {
                table2[val-1]++;
            }
            if(!found && table[val-1] == 1) {
                sum1 += val;
                found = true;
            }
            table[val-1] = 2;
        }
        if(counter == 3) {
            for(short i=0; i<52; i++) {
                if(table2[i] == 3) {
                    sum2 += i+1;
                    break;
                }
            }
            memset(table2, 0, 52*sizeof(short));
            counter = 0;
        }
        start = end+2;
        end = strchr(end+2, '\n');
    }

    result.part1 = sum1;
    result.part2 = sum2;
    return result;
}

AOC_MAIN(day03);
