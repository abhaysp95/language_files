#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-12
Description: pattern printing (power of 2)
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-12
"""

n = int(input())
for i in range(1, n+1):
    for j in range(i, 0, -1):
        print(2**(j-1), " ", end="")
    print()
