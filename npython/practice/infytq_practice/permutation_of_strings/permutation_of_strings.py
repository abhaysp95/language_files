#!/usr/bin/env python3

from itertools import permutations

def get_permutation(string):
    perm_list = list()
    for x in permutations(string, len(string)):
        perm_list.append("".join(x))
    return perm_list

count = int(input())
for _ in range(count):
    print(" ".join(sorted(get_permutation(input()))))
