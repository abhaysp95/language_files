#!/usr/bin/env python3

def fact_sum(n):
    s = 1
    for j in range(2, n + 1):
        if (n - (n // j) * j) == 0:
            s += j
    return s

tc = int(input())

for _ in range(tc):
    lst = list(map(int, input().split(',')))

    outlst = list()
    for x in lst:
        s = fact_sum(x)
        if s in lst:
            outlst.append(x)
    if len(outlst) == 0:
        print("-1".strip())
    else:
        print(sorted(outlst))
