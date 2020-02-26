#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-26
Description: Create abbreviation of name
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-26
"""

lst = input().split()
for x in range(len(lst)):
    if len(lst)==1:
        n = lst[x]
        print(n[0]+str("."))
    elif x == len(lst)-1:
        n = lst[x]
        print(n, end=" ")
    else:
        n = lst[x]
        print(n[0]+str("."),end=" ")
