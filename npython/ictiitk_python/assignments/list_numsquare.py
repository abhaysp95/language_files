#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-17
Description: Make a list for number from -10 to 0 and there square
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-17
"""

# logic <<<
num_lst = []
x = 0
num_lst = [(x, x ** 2) for x in range(-10, 0)]
print(num_lst)
# >>>
