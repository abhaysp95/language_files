#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-03
Description: Spell name in abbreviated form
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-03
"""

# variables <<<
name = input('Enter the name: ')
space = []
# >>>

# first name <<<
print('Name in abbreviated form')
print(name[0], end='')
print('.', end=' ')
# >>>

# all the spaces in names <<<
for i in range(len(name)):
    if (name[i] == ' '):
        space.append(i)
# >>>

# all the middle names <<<
for i in range(len(space) - 1):
    print(name[space[i] + 1], end='')
    print('.', end=' ')
# >>>

print(name[space[-1] + 1:])
# >>>
