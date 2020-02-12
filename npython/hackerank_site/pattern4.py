#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-12
Description: pyramid (half reverse)
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-12
"""

n=int(input())
for i in range(1, n+1):
    print(' '*(n-i),end="")
    for j in range(1, i+1):
        print(j,end="")
    for j in range(i-1,0,-1):
        print(j,end="")
    print()

