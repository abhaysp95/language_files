#!/usr/bin/env python3

import re

tc = int(input())

def get_bounded_region(sentence):
    ones = 1
    twos = 2
    all_ones = re.findall(r'[abdegopq4690ADOPQR]', sentence)
    all_twos = re.findall(r'[B8]', sentence)
    total_sum = len(all_ones) + len(all_twos) * 2
    return total_sum

for _ in range(tc):
    words = int(input())
    sentence = input()
    print(get_bounded_region(sentence))
