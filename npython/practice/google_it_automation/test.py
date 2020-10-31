#!/usr/bin/env python3

import csv

dct = dict()
count = 0
with open('test.csv', 'r') as file:
    # lines = file.readlines()
    # for line in lines:
        # ssplit = line.split(' ')
        # dct[ssplit[0]] = ' '.join(ssplit[1:])
    lines = file.read().splitlines()
    for line in lines:
        print("1: " + line)


# for key, value in dct.items():
    # print(f"key: {key}, value: {value}")
