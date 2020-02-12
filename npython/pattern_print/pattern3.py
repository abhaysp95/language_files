#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-12
Description: triangular half pyramid reverse number
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-12
"""

num = int(input())
for i in range(1, num+1):
    for j in range(i, 0, -1):
        print(j,end="")
    print()
