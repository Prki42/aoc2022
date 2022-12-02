#include "../shared/aoc.h"

struct Result solve(const char* input) {
    struct Result result;
    int score1 = 0;
    int score2 = 0;
    size_t len = strlen(input);
    for(size_t i=0; i<len; i+=4) {
        short left = (int)(input[i]+1) % 3;
        short right = (int)(input[i+2]+2) % 3;
        score1 += (left != right) ? ((right+1)%3 != left)*6 + right+1 : (right + 4);
        score2 += (right==0)*((left+2)%3 + 1) + (right==1)*(left + 4) + (right==2)*((left+1)%3 + 7);
    }

    result.part1 = score1;
    result.part2 = score2;
    return result;
}

AOC_MAIN(day02);
