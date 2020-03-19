#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-18
Description: learning if else in python
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-18
"""

# print bmw, dodge in upper case, rest in title case

# logic <<<
cars = ['audi', 'mercedes', 'porsche', 'dodge', 'playmoth', 'bmw', 'chevorlet']

for car in cars:
    # if car == 'bmw' or car = 'car':       use below method if you come to this type of syntax
    # if car == ('bmw', 'dodge'):

    # even better way
    ncar = ['bmw', 'dodge']
    if car in ncar:
        print(car.upper())
    else:
        print(car.title())
    # print the value True/False for every value of car
    print("Value of if/else is: ", car in ncar, end='\n')
    print()
# >>>
