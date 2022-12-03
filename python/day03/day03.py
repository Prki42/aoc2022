def charToVal(x):
    return ord(x)-ord('A')+27 if ord(x) < ord('a') else ord(x)-ord('a')+1

def part1(line):
    return list(map(lambda x: charToVal(x[0]), filter(lambda x: x[1], map(lambda x: (x, x in line[(len(line)//2):]), line[:(len(line)//2)]))))[0]

def part2(lines):
    return list(map(lambda x: charToVal(x[0]), filter(lambda x: x[1], map(lambda x: (x, x in lines[1] and x in lines[2]), lines[0]))))[0]

with open("input.txt") as f:
    print((lambda x: (sum(map(part1, x)), sum(map(part2, [x[i:i+3] for i in range(0, len(x), 3)]))))(f.read().strip().split("\n")))
