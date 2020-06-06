#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-19
Description: Input in string format, find how many times a number is
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-19
"""

num = int(input("Enter the count: "))
print("Enter string")
lst = [int(x) for x in input().split()]     # taking input and spliting it
find = int(input('Enter element to get count of: '))
c = 0
for n in range(num):
    if find == lst[n]:  # or if find == lst[n]:
        c += 1
print(c)
