#!/usr/bin/env python3

count = int(input())
occurance={}
for x in input().split():
    if x in occurance.keys():
        occurance[x] += 1
    else:
        occurance[x] = 1

for key, value in occurance.items():
    if value == 1:
        print(key)
