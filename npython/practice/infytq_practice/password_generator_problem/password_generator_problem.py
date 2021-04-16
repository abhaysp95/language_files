#!/usr/bin/env python3

pairs = input().split(',')
final_string = ""

for pair in pairs:
    pair_list = pair.split(':')
    num = int(pair_list[1])
    str_len = len(pair_list[0])
    position = -1
    while (num > 0):
        # print("num:", num)
        rem = num % 10
        num //= 10
        if position < rem and rem <= str_len:
            position = rem
    if position < 0:
        final_string += 'X'
    else:
        final_string += pair_list[0][position - 1]

print(final_string)
