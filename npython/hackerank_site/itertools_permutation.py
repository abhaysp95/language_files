#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
practicing permutations method with itertools
"""

from itertools import permutations


def first_method(get_sequence):
    '''first function'''
    # given sequence can be list, string etc.
    return list(permutations(get_sequence))


def second_method(get_sequence, length):
    '''second_function'''
    get_sequence = sorted(get_sequence)
    return list(permutations(get_sequence, int(length)))


def main():
    '''inside main function'''
    seq, length = input().split()
    result = second_method(seq, length)
    # print(result)
    for tup in result:
        for char in tup:
            print(char, end='')
        print()


if __name__ == "__main__":
    main()
