#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-05
Description: tower of hanoi problem
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-05
"""

PROMPT = '> '


class TowerOfHanoi:  # pylint: disable=too-few-public-methods
    '''class for tower of hanoi'''

    def __init__(self, dcount, first, second, third):
        self.disk_count = dcount
        self.first = first
        self.second = second
        self.third = third
        self.cycle = 0

    def get_cycle(self):
        '''object function to get cycle num and do recursion'''
        if self.disk_count > 0:
            TowerOfHanoi.get_cycle(self.disk_count - 1, self.first,
                                   self.third, self.second)
            print('Moving last disk from ', self.first, ' to ', self.third)
            self.cycle += 1
            TowerOfHanoi.get_cycle(self.disk_count - 1, self.second,
                                   self.first, self.third)


def main():
    '''Entering in main function'''
    print('Enter disk number: ')
    number = int(input(PROMPT))
    first_object = TowerOfHanoi(number, 1, 2, 3)
    first_object.get_cycle()


if __name__ == "__main__":
    main()
