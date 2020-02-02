#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-02
Description: Implementing sort() method
Email: abhaysp9955@gmail.com
Last Edited: 2020-02-02
"""

cars = ['bmw', 'dodge', 'aston martin', 'porsche', 'mclaren']
# by default it sorts in alphabetical order and we will not be able to revert back to orignal order
cars.sort()
print(cars)

# sort lists in reverse alphabetical order
cars.sort(reverse=True)
print(cars)

print("\n Here is the orignal list: ")
cars = ['bmw', 'dodge', 'aston martin', 'porsche', 'mclaren']
print(cars)

print("\nHere is the sorted list: ")
print(sorted(cars))

print("\nHere is the reverse sorted list: ")
print(sorted(cars, reverse=True))

print("\n Here is the orignal list again: ")
print("\n", cars)

cars.reverse()
print("\n", cars)

cars.reverse()
print("\n", cars)

print("\nLength of the list is: ", len(cars))
