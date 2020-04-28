#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-26
Description: arbitrary number of argument in function
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-26
"""

PROMPT = '> '


# function to show <<<
def make_pizza(*toppings):
    '''Summarize the pizza we are about to make'''
    print('\nMaking the following toppings:')
    print(type(toppings))
    for topping in toppings:
        print(PROMPT, f"{topping}.title()")
# >>>


# main function <<<
def main():
    '''Entering in main function'''
    get_pizza_toppings = []

    # take inputs
    print('press "q" to quit entering')
    # value = input(PROMPT)
    # get_pizza_toppings.append(value)
    while True:
        value = input(PROMPT)
        if value == 'q':
            break
        get_pizza_toppings.append(value)

    print('toppings are: ', get_pizza_toppings)
    make_pizza(name for name in get_pizza_toppings)
# >>>


if __name__ == "__main__":
    main()
