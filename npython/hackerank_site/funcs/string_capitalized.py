#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: String capitalized
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# <<<
string = input('Enter the string: \n')
# the one below is one line solution
# print(string.upper())

str_lst = list(string)

cap_strlst = list(map(lambda x: x.upper(), str_lst))

print('String in capital: \n', ''.join(cap_strlst))

# >>>

