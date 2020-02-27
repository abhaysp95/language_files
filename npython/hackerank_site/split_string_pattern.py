#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-27
Description: Make pattern from given string(triangle form)
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-27
"""

name = input()
# for i in range(0, len(name)):
#     for j in range(0, i + 1):
#         print(name[j], end="")
#     print()
# above one is not so pythonic

for i in range(len(name)):
    print(name[0:i+1])
