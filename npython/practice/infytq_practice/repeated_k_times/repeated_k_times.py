#!/usr/bin/env python3

arr_len = int(input())
arr = list(map(int, input().split()))
repeatition = int(input())

arr_dict = dict()
for num in arr:
    try:
        arr_dict[num] += 1
    except KeyError:
        arr_dict[num] = 1

min_num = 284309238409
for key, value in arr_dict.items():
    if value == repeatition:
        min_num = min(min_num, key)
print(min_num)
