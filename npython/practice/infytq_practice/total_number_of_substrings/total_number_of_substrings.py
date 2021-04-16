#!/usr/bin/env python3

string, character = input().split(',')

len_str = len(string)
count = 0
for idx1 in range(len_str):
    for idx2 in range(idx1 + 1, len_str + 1):
        if character not in string[idx1:idx2]:
            count += 1
print(count)
