#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-20
Description: Check whether a substring foun in string
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-20
"""

# first approach <<<
# variable declaration <<<
str1 = input('Enter the string: ')
str2 = input('Enter the substring: ')
# c=0
# >>>

# condition check <<<
# for i in str2:
#     if i in str1:
#         c += 1

# if c == len(str2):
#     print('Substring found in the string')
# else:
#     print('Substring not found in string')
# >>>
# issue in this is it check whether all the elements are in string or not
# not a particular set of string in continuous manner
# >>>

# second method <<<
# if str2 in str1:
#     print("Substring found in string")
# else:
#     print("Substring not found in string")
# >>>

# third method <<<
# find() returns integer, if string found then starting index of String for substring, else returns -1
if str1.find(str2) >= 0:
    print("Substring found in string")
else:
    print("Substring not found in string")
# >>>
