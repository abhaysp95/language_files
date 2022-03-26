#!/usr/bin/env python3

from itertools import permutations

def func(n, arr):
    temp = set()
    for x in permutations(arr, 3):
        print(sum(x))
    return len(temp)

def main():
    n = int(input())
    arr = [int(x) for x in input().split()]
    x = func(n, arr)
    print(x)

main()
