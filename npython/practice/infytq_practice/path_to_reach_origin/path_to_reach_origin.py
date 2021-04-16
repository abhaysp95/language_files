#!/usr/bin/env python3

from math import factorial

tc = int(input())

def unique_ways_to_origin(x, y):
    return int((factorial(x + y) / (factorial(x) * factorial(y))))

for _ in range(tc):
    x, y = [int(x) for x in input().split()]
    print(unique_ways_to_origin(x, y))
