#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-13
Description: Full triangle pyramid using star
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-13
"""

print("Program to print full pyramid with *")
num=int(input())
for i in range(1, num+1):
    for j in range(1, num-i+1):
        print(" ", end="")
    for k in range(0, (2*i)-1):
        print("*", end="")
    print()
