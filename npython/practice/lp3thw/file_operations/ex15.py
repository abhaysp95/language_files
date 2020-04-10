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
    # gets script and filename from argv
    script, filename = argv  # pylint: disable = W0632
    print(f"I'm {script}")
    # opens file in txt
    txt = open(filename, 'a')
    print(f"Here's your file (filename):")
    # reads opened file in txt
    print(txt.read())
    # closing the opened file
    txt.close()
    print("Type the filename again: ")
    # after finishing read, prompts again for input
    file_again = input(prompt)
    # again opens
    txt_again = open(file_again)
    # again reads
    print(txt_again.read())
    # close file
    txt_again.close()


if __name__ == '__main__':
    print(main.__doc__)
    main()
