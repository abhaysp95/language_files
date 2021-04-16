#!/usr/bin/env python3

from itertools import permutations

tc = int(input())

def get_max_num(num_list):
    perm_list = list()
    for perm in permutations(num_list):
        perm_list.append(int("".join(perm)))
    return max(perm_list)

for _ in range(tc):
    # num_list = list(map(int, input().split()))  # another way to make make list elements int
    num_list = input().split()
    print(get_max_num(num_list))
