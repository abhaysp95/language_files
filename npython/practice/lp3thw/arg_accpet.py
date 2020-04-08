#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-07
Description: taking input with argument
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-07
"""

from sys import argv


def main():
    '''taking args for input'''
    awor, bwor, cwor, dwor = argv  # pylint: disable=W0632
    # pylint: disable=unbalanced-tuple-unpacking
    script = argv
    first = input('Enter the first value: ')
    second = argv
    third = input('Enter the third value: ')

    print("The script is called: ", script)
    print('These are first four arguments: ', awor, '\n', bwor, '\n',
          cwor, '\n', dwor)
    print("Your first variable is: ", first)
    print("Your second variable is: ", second)
    print("Your third variable is: ", third)
    print('Type of argv is: ', type(argv))


if __name__ == "__main__":
    print(main.__doc__)
    main()
