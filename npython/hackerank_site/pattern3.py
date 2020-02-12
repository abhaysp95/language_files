#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-12
Description: star pyramid
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-12
"""

n=5
t=1
sp=n-1
for i in range(n):
    print(' '*sp,end="")
    print('*'*t)
    t+=2
    sp-=1

