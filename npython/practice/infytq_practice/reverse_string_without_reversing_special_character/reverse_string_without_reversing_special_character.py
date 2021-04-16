#!/usr/bin/env python3

tc = int(input())

for _ in range(tc):
    lstr = list(input())
    back = len(lstr) - 1
    front = 0
    while (front < back):
        if not lstr[front].isalpha():
            front += 1
        if not lstr[back].isalpha():
            back -= 1
        lstr[front], lstr[back] = lstr[back], lstr[front]
        front += 1
        back -= 1
    print(''.join(lstr))
