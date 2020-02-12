#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-12
Description: pattern pyramid with continuous number
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-12
"""

num = int(input())
n=1
for i in range(1, num+1):
    for j in range(1, (2*i)):
        print(n, " ", end="")
        n+=1
    print()
