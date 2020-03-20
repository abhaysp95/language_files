#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-20
Description: Check if entered name is found or not
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-20
"""

# variable declaration <<<
lst = []
count = int(input('Enter the count for total names: '))

print('Enter the names: ')

# appending names <<<
for i in range(count):
    print(i + 1, ': ', end='')
    lst.append(input())
# >>>

name = input('Enter the name to find: ')
# >>>

# find name <<<
if name in lst:
    print('Name found')
else:
    print('Name not found')
# >>>
