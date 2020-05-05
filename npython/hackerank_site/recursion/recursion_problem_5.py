#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-05
Description: tower of hanoi problem
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-05
"""

PROMPT = '> '


# function for recursion
def toh(count, first, second, third):
    '''function of recursion for tower of hanoi'''
    if count > 0:
        toh(count - 1, first, third, second)
        print('(', first, ',', third, ')')
        toh(count - 1, second, first, third)


def main():
    '''Inside main function'''
    print('Enter the disk count: ')
    number = input(PROMPT)
    number = int(number)
    toh(number, 1, 2, 3)


if __name__ == "__main__":
    main()
