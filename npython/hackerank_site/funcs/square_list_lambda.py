#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: Squaring list usin lambda
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# getting input <<<
nums = input('Give space seperated numbers: ')
lst = list(map(int, nums.split()))
# >>>

# making logic <<<
sq_lst = list(map(lambda x: x**2, lst))
# >>>

# printing <<<
print(' '.join(map(str, sq_lst)))
# >>>
