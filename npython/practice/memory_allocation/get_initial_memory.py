#!/usr/bin/env python3

'''
get the size of empty objects of several basic data structures
'''

from sys import getsizeof


def sizes():
    '''get size'''
    print('size of "": {}'.format(getsizeof("")))
    print('size of []: {}'.format(getsizeof([])))

    print('size of (): {}'.format(getsizeof(())))
    print('size of {}: ', getsizeof({}))

    print('size of set(): {}'.format(getsizeof(set())))
    print('size of dict(): {}'.format(getsizeof(dict())))
    print('size of list(): {}'.format(getsizeof(list())))

    print('size of 1: {}'.format(getsizeof(1)))
    print('size of True: {}'.format(getsizeof(True)))
    print('size of 0: {}'.format(getsizeof(0)))
    print('size of False: {}'.format(getsizeof(False)))


if __name__ == "__main__":
    sizes()
