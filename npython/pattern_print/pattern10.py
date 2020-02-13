#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-13
Description: 90-degree clockwise rotated full pyramid(*)
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-13
"""

print("Enter the number: ")
num = int(input())
j = 1
for i in range(1, num+1):
    print("* "*j, end="")
    j += 1
    print()
j = num-1
for i in range(1, num):
    print("* "*j, end="")
    j -= 1
    print()
