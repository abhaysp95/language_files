#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-12
Description: Normal pattern
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-12
"""

n = int(input())
for i in range(1, n+1):
    for j in range(0, i):
        print(i, end="")
    print()
