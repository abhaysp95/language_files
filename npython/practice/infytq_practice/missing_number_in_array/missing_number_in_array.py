#!/usr/bin/env python3

from functools import reduce

tc = int(input())

def return_missing(arr, arr_len):
    tot_sum = reduce(lambda x, y: x + y, list(range(1, arr_len + 1)))
    got_sum = reduce(lambda x, y: x + y, arr)
    return tot_sum - got_sum

for _ in range(tc):
    arr_len = int(input())
    arr = [int(x) for x in input().split()]
    print(return_missing(arr, arr_len))
