#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-12
Description: Pattern 4 my approach
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-12
"""

n=int(input())
sp=n-1
t=1
for i in range(n):
    print(' '*sp,end="")
    for j in range(1, t+1):
        print(j, end="")
    for k in range(j-1, 0, -1):
        print(k, end="")
        j-=1
    print()
    t+=1
    sp-=1

