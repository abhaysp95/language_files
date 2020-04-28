#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-26
Description: making module for pizza toppings
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-26
"""

from sys import argv

PROMPT = "> "
SCRIPT_NAME = argv


# function to make pizza <<<
def make_pizza(size, *toppings):
    '''Summarize the pizza that we are about to make'''
    print(f"Making the {size} inch pizza with the following toppings:")
    for topping in toppings:
        print(PROMPT, f"{topping}")
# >>>


# main function <<<
def main():
    '''inside main function'''
    make_pizza(10, 'butter', 'capcicum')
# >>>


if __name__ == "__main__":
    print(f"Running {SCRIPT_NAME} directly")
    print(main.__doc__)
    main()
else:
    print(f"Running {SCRIPT_NAME} as a module")
