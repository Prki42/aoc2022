def prepare(line: str):
    return list(map(lambda x: list(map(lambda y: int(y), x.split('-'))), line.split(',')))

def part1(x):
    return min(x[0][1]-x[0][0], x[1][1]-x[1][0])+1 == max(0, min(x[0][1], x[1][1]) - max(x[0][0], x[1][0])+1)

def part2(x):
    return max(0, min(x[0][1], x[1][1]) - max(x[0][0], x[1][0])+1) != 0

with open('input.txt') as f:
    print((lambda x: (list(map(part1, x)).count(True), list(map(part2, x)).count(True)))(list(map(prepare, f.read().strip().split('\n')))))
