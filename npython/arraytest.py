#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-15
Description: testing array
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-15
"""

size = int(input("Enter the number for elements: "))
lst = []
print("Enter ", size, "Elements :")
for i in range(size):
    n = int(input())
    lst.append(n)
print("Given elements are: ")
for i in range(len(lst)):
    print(lst[i])
