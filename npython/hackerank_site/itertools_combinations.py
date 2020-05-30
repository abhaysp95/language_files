#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
practice on combinations method of itertools module
"""

from itertools import combinations


def get_combination(get_sequence, length):
    '''returns the combination'''
    get_sequence = sorted(get_sequence)
    result = []
    for count in range(1, length + 1):
        # print(result)
        result += list(combinations(get_sequence, count))
    return result


def main():
    '''inside main function'''
    word, length = input().split(' ')
    result = get_combination(word, int(length))
    # print('in main')
    for tup in result:
        for char in tup:
            print(char, end='')
        print()


if __name__ == "__main__":
    main()
