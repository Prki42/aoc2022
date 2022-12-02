def part1(line: str):
    points = 0
    if line[2] == "Y":
        points += 2
        if line[0] == "A":
            points += 6
        elif line[0] == "B":
            points += 3
    elif line[2] == "Z":
        points += 3
        if line[0] == "B":
            points += 6
        elif line[0] == "C":
            points += 3
    else:
        points += 1
        if line[0] == "C":
            points += 6
        elif line[0] == "A":
            points += 3
    return points

def part2(line: str):
    if line[0] == "B":
        if line[2] == "X":
            return 1
        if line[2] == "Y":
            return 5
        return 9
    if line[0] == "A":
        if line[2] == "X":
            return 3
        if line[2] == "Y":
            return 4
        return 8
    if line[0] == "C":
        if line[2] == "X":
            return 2
        if line[2] == "Y":
            return 6
        return 7
        

with open("./input.txt") as f:
    result = (lambda x: (sum(map(part1, x)), sum(map(part2, x))))(f.read().strip().split("\n"))
    print(result)
