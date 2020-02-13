#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-13
Description: Full pryramid with *
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-13
"""

print("Somewhat different from pattern7 \n Enter the number: ")
num = int(input())
m = (2*num)-2
for i in range(0, num):
    for j in range(0, m):
        print(end=" ")
    # print(' '*m,end="")
    m = m-1 # decrementing m after each row
    for j in range(0, i + 1):
        print("*", end="")
    print()
