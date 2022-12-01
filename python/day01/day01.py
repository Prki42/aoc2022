with open ("./input.txt") as f: print((lambda x: (x[0], sum(x)))(sorted(list(map(lambda x: sum([int(y) for y in x.split("\n")]), f.read().strip().split("\n\n"))), reverse=True)[:3]))
