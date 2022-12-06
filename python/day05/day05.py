from typing import List
from collections import namedtuple


Instruction = namedtuple('Instruction', ['source', 'destination', 'ammount'])

def parseCargo(input: List[str]) -> List[List[str]]:
    n = int(input[-1].split()[-1])
    lst :List[List[str]]= [[] for _ in range(n)]
    for x in input[::-1][1:]:
        x += ' '
        for i, val in enumerate([x[j:j+4] for j in range(0, len(x), 4)]):
            if val.strip() == '':
                continue
            lst[i].append(val[1])
    return lst

def parseInstructions(input: List[str]) -> List[Instruction]:
    lst : List[Instruction] = []
    for x in input:
        words = x.split();
        lst.append(Instruction(int(words[3])-1, int(words[5])-1, int(words[1])))
    return lst

def solve(input: List[str], part: int):
    cargo = parseCargo(input[0].split('\n'))
    instructions = parseInstructions(input[1].rsplit('\n'))

    for inst in instructions:
        if part == 1:
            cargo[inst.destination] += (cargo[inst.source][-(inst.ammount):])[::-1]
        else:
            cargo[inst.destination] += (cargo[inst.source][-(inst.ammount):])
        cargo[inst.source] = cargo[inst.source][:-(inst.ammount)]
    
    msg = ''
    for c in cargo:
        msg += c[-1]

    return msg

with open('input.txt') as f:
    input = f.read().rstrip().split("\n\n")
    print(f'({solve(input, 1)}, {solve(input, 2)})')