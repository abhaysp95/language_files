#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-06
Description: making a rollabale dice with different sides
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-06
"""

from random import randint


# class for dice
class Die:  # pylint: disable=too-few-public-methods
    '''class for rollable dice'''

    def __init__(self, sides=6):
        '''init method for class Die'''
        self.sides = sides
        # self.roll = 10

    def roll_die(self):
        '''giving random number'''
        return randint(1, self.sides)

    def cycles(self, count):
        '''rolling die 10 times'''
        while count > 0:
            print(self.roll_die())
            count -= 1


def main():
    '''Inside main function'''
    num = 10

    first_dice = Die()
    second_dice = Die(10)
    third_dice = Die(20)

    first_dice.cycles(10)

    while num > 0:
        print('First dice: ', first_dice.roll_die())
        print('Second dice: ', second_dice.roll_die())
        print('Third dice: ', third_dice.roll_die())
        num -= 1


if __name__ == "__main__":
    main()
