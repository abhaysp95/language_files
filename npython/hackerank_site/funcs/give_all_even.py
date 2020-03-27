#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: WAP to filer even elements from list using lambda, if no even then print -1
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# <<<
# lst = [int(input()) for _ in range(int(input()))]

count = int(input())
nums = input()
lst = list(map(int, nums.split()))

print(lst)
type(lst)

even_lst = list(filter(lambda x: x % 2 == 0, lst))

print('Even list is:\n', even_lst)

if len(even_lst) != 0:
    print('Even list is:\n', ' '.join(map(str, even_lst)))
else:
    print('-1')

# >>>
