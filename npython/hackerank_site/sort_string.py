#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-20
Description: sort string
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-20
"""

# non - pythonic way:

# declaring variabales: <<<
str1 = input('Enter the string: ')
# >>>

# converting str into list
# it's needed to create list as str doesn't supports item assignment
# lst = list(str1)

# sorting string: <<<
# for i in range(len(str1) - 1):
#     for j in range(i + 1, len(str1)):
#         if str1[i] > str1[j]:
#             lst[i], lst[j] = lst[j], lst[i]
# >>>

# print <<<
# print(f"Sorted string is {str1}")
# print('Sorted string is', ''.join(lst))
# >>>

# some pythonic approach <<<
# str1 decleration is at top
print('Sorted string is: ', ''.join(sorted(str1)))
# <<<
