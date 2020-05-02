#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-30
Description: factorail with recursion
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-30
"""


# function to calculate factorial <<<
def get_factorial(number):
    '''getting factorial value'''
    if number in (0, 1):
        return 1
    else:
        return number * get_factorial(number - 1)
# >>>


# main function <<<
def main():
    '''Entering in main function'''
    fnum = int(input('Enter the number: '))

    fact = get_factorial(fnum)
    print("Factorial is: ", fact)
# >>>


if __name__ == "__main__":
    main()
