#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-20
Description: Remove everything except alphabet
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-20
"""

import itertools as itt


# variable declaration
WORD = input('Enter the string: ')
NEW_WORD = ''

# iteration <<<
for alphabet in WORD:
    if 'a' <= alphabet <= 'z':
        print(alphabet, end='')
    elif 'A' <= alphabet <= 'Z':
        print(alphabet, end='')

for i in itt.chain(range(65, 91), range(97, 123)):
    if chr(i) in WORD:
        NEW_WORD = NEW_WORD + chr(i)

print(NEW_WORD)

# this method doesn't works
# NEW_WORD = ''
# for i in range(65, 91) + range(97, 123):
#     if chr(i) in WORD:
#         NEW_WORD = NEW_WORD + chr(i)

NEW_WORD = ''
for i in list(range(65, 91)) + list(range(97, 123)):
    if chr(i) in WORD:
        NEW_WORD = NEW_WORD + chr(i)
print(NEW_WORD)
# >>>

# how to do comparision with ascii code in python?
