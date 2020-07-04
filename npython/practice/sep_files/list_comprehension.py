#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-20
Description: List comprehension
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-20
"""

lst1 = [x for x in range(10)]
print('Fisrt list')
print(lst1)

lst2 = [x for x in range(20) if x%5==0]
print('Second list')
print(lst2)

lst3 = [int(x) for x in range(10) for x in range(5)]
print('Third list')
print(lst3)
