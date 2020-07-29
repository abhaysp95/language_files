#!/usr/bin/env python3

'''
demonstration of builtins
'''

import builtins


def check_builtins():
    '''check for builtins function'''
    list = [1, 2, 3, 4]
    print(list[list[2]])

    print(builtins.list([3]))
    print(builtins.list([3, 8]))

    # now checking builtins
    print(builtins.list(list[list[0]:4]))


if __name__ == "__main__":
    check_builtins()
