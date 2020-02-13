#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-13
Description: Print inverted half pyramid(*)
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-13
"""

print("Printing inverted half pyramid \nEnter the number: ")
num = int(input())
j = num
for i in range(1, num+1):
    print("*"*j, end="")
    j -= 1
    print()
