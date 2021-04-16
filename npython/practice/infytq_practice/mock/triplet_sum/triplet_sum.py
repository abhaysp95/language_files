#!/usr/bin/env python3

from itertools import permutations

arr = list(map(int, input().split()))

permute_list = permutations(arr, 3)
out_list = list()

for out in permute_list:
    if out not in out_list:
        out_list.append(out)

# print(out_list)

max_sum = 0
for pair in out_list:
    ai, aj, ak = pair
    if arr.index(ai) < arr.index(aj) and arr.index(aj) < arr.index(ak):
        if ai < aj and aj < ak:
            max_sum = max(max_sum, ai + aj + ak)

print(max_sum)
