#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: Create a dict from the lists
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# <<<
count = int(input('Enter the elements of dict: '))
nlst = [input('Enter the keys: ') for _ in range(count)]
alst = [input('Enter the values: ') for _ in range(count)]

print('nlst: \n', nlst)
print('alst: \n', alst)

ndict = dict(zip(nlst, alst))
# by default, zip returns in tuple format
# you can use zip for more than 2 lists also but tuple not dict

print('Keys are: \n', ndict.keys())
print('Values are: \n', ndict.values())
print('Items are: \n', ndict.items())
print('Dict is: \n', ndict)
print('Sum of values in dict: ', sum(ndict.values()))

# >>>
