#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: Store individual letters and it's iteration in dict
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: date
"""

# variable declaration <<<
name = input('Enter the string: ')
nlst = []
alst = []
# >>>

# loop <<<
for letter in name:
    if letter not in nlst:
        nlst.append(letter)

for letter in nlst:
    count = 0
    for letters in name:
        if letter == letters:
            count = count + 1
    alst.append(count)
# >>>

# print <<<
print('Name list is: \n', nlst)
print('Count list is: \n', alst)
print('Dict is: \n', dict(zip(nlst, alst)))
# >>>
