#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-19
Description: Diff max and min, input of list in form of string
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-19
"""

num = int(input("Enter the count: "))
print('Enter the string: ')
lst = [int(x) for x in input().split()]
print("Difference is: ", max(lst) - min(lst))
