#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-19
Description: Unique print in optimized way
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-19
"""

n = int(input('Enter the count: '))
lst = []
for i in range(n):
    lst.append(int(input()))
unq = []
for n in lst:
    if n in unq:
        pass
    else:
        unq.append(n)
print("\nOutput: ")
for i in unq:
    print(i)
