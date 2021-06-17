#!/usr/bin/env python3

from collections import defaultdict

def get_next_max(arr, x):
    # print(arr, x)
    dd = defaultdict(int)
    max_count = -1
    max_num = -1
    for elem in arr:
        if elem > x:
            dd[elem] += 1
    if len(dd) == 0:
        return -1
    else:
        # print(dd)
        for key, value in dd.items():
            if value > max_count:
                max_num = key
                max_count = value
                # print("if:", max_num)
            elif value == max_count:
                max_num = min(max_num, key)
                # print("else:", max_num)
    return max_num

inarr = list(map(int, input().split(',')))

outarr = list()

for i, x in enumerate(inarr):
    next_max = get_next_max(inarr[i + 1:], x)
    # print(x, next_max)
    outarr.append(next_max)
outarr = list(str(x) for x in outarr)
print(",".join(outarr).strip())
