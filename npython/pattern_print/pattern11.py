#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-13
Description: Reverse pyramid number(can't explain)
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-13
"""

print("Enter the number: ")
num = int(input())
for i in range(1, num+2):
    for j in range(0, num+2-i):
        print(j, end="")
    print()
