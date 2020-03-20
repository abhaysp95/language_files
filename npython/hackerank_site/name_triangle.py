#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-20
Description: Making name right angle triangle
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-20
"""

# declaring variables:
name = input('Enter the name: ')

# iteration <<<
for i in range(len(name)):
    for j in range(i + 1):
        print(name[j], end='')
    print()
# >>>
