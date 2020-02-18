#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-17
Description: using loop in python
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-17
"""

magicians = ['alice', 'david', 'caroline']
for magician in magicians:
    print("Magician: ", magician)
    print(f"{magician.title()}, that was a great trick")
    print(f"I can't wait to see the next trick, {magician.title()}. \n")

numbers = list(range(1, 6))
print(numbers)

even = list(range(2, 11, 2))    # even value up to 10
print("Even numbers: ", even)

squares = []    # empty list
for value in range(1, 11):
    # square = value ** 2
    squares.append(value ** 2)
print("\nSquares of numbers from 1 to 10: ")
print(squares)

print("Max element: ", max(squares))
print("Min element: ", min(squares))
print("Sum: ", sum(squares))

# now using list comprehension

cubes = [value ** 3 for value in range(1, 11)]
print("\nCubes of numbers from 1 to 10: ")
print(cubes)
