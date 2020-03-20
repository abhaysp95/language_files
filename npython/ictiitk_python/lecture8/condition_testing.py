#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-19
Description: Basic program for condition testing
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-19
"""

fruits = ['apple', 'mango', 'guava', 'grapes']
fruit = input('Enter the fruit name: ')

if fruit not in fruits:
    print(f"{fruit.title()}, it has to be bought yet.")
else:
    print(f"{fruit.title()}, it has already been bought.")
