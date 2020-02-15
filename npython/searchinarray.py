#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-15
Description: Search an element in array
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-15
"""

size = int(input("Enter size of list: "))
lst = []
print("Enter ", size, "Elements: ")
for i in range(size):
    lst.append(int(input()))

num = int(input("Enter the number to search: "))

if num in lst:
    print("Element found: ")
else:
    print("Element Not found")


