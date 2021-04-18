#!/usr/bin/env python3

tc = int(input())

for _ in range(tc):
    string = input()

    output = list()
    for x in string:
        num = int(x)
        prod = num * (num - 1)
        if str(prod) in string:
            output.append(prod)
    if len(output) == 0:
        print("-1".strip())
    else:
        print(sorted(output))
