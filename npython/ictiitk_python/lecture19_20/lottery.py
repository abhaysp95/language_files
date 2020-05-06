#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-06
Description: declaring lottery winner
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-06
"""

import random


# class for getting lottery
class Lottery:  # pylint: disable=too-few-public-methods
    '''tells lottery serial and winner'''
    def __init__(self, series):
        '''init method for lottery class'''
        self.series = series

    def gen_series(self):
        '''get random values from given list sequence'''
        return random.choices(self.series, k=5)

    def print_series(self):
        '''printing winner'''
        # got_series = Lottery.get_series(self)
        # for val in got_series:
        got_series = ''
        for val in self.gen_series():
            got_series = got_series + val
        return got_series

    def my_ticket(self, my_seq):
        '''rounds till I get my sequences matched'''
        count = 1
        get_series = self.print_series()
        while get_series != my_seq:
            get_series = self.gen_series()
            count += 1
        print('To make you winner number of sequences generated were ', count)


def main():
    '''Inside main function'''
    print('Enter combination of letters and number combined', end=' ')
    print('shouldn\'t be greater than 15 in count')
    lst = [value for value in input().split(' ')]
    first_ticket = Lottery(lst)

    print(first_ticket.print_series())
    my_seq = Lottery(lst)
    my_seq.my_ticket('23cda')


if __name__ == "__main__":
    main()
