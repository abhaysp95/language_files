#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: date
Description: reverse pattern
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-10
"""

n = int(input("Enter the number: "))
for i in range(1, n+1):
    for j in range(1, n):
        if j < i:
            print(" ",end="")
    for k in range(1, n-i+2):
        print(k,end="")
    print()

