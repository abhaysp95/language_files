#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-24
Description: Basic lambda trail
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-24
"""

lst = [int(input()) for _ in range(int(input()))]
print(lst)

# filter takes in two arguments - a function and a list
nlst = list(filter(lambda x: (x%2 == 0), lst))
print(nlst)

mlst = (x for x in lst if x%2 == 0)
print(list(mlst))

# map also takes a list and function as argument
plst = list(map(lambda x: x * 2, lst))
print(plst)
