#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-13
Description: Can't Explain
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-13
"""

print("Enter the number of rows: ")
num = int(input())
c = 0
for i in range(0, num):
    for j in range(0, i+1):
        print(c, " ", end="")
        c = 2**(i+1)
    print()
