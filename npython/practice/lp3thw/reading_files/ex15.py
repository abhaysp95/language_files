#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-07
Description: this example will tell for reading file
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-07
"""

# this file will read content from ex15_sample.txt

from sys import argv


def main():
    '''entering in main function'''
    prompt = '> '
    script, filename = argv  # pylint: disable = W0632

    print(f"I'm {script}")

    txt = open(filename)

    print(f"Here's your file (filename):")
    print(txt.read())

    print("Type the filename again: ")
    file_again = input(prompt)

    txt_again = open(file_again)

    print(txt_again.read())


if __name__ == '__main__':
    print(main.__doc__)
    main()
