#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
make a alphabet rangoli
"""

import string


def print_rangoli(size):
    '''function to print rangoli'''
    # top triangle
    for num in range(size - 1, 0, -1):
        print('-' * 2 * num, end='')
        tlst = [chr(x + 96) for x in range(size, num, -1)]
        tlst += [chr(x + 97) for x in range(num + 1, size)]
        print('-'.join(tlst), end='')
        print('-' * 2 * num)

    # middle belt
    mmlst = [chr(x + 96) for x in range(size, 0, -1)]
    mmlst += [chr(x + 96) for x in range(2, size + 1)]
    print('-'.join(mmlst))

    # bottom traingle
    for num in range(1, size):
        print('-' * 2 * num, end='')
        blst = [chr(x + 96) for x in range(size, num, -1)]
        blst += [chr(x + 97) for x in range(num + 1, size)]
        print('-'.join(blst), end='')
        print('-' * 2 * num)


def print_rangoli2(size):
    '''print rangoli but better'''
    get_str = 'abcdefghijklmnopqrstuvwxyz'[:size]

    for count in range(size - 1, -size, -1):
        count = abs(count)
        line = get_str[size:count:-1] + get_str[count:size]
        # print("--" * count + '-'.join(line) + "--" * count)
        print(('-'.join(line)).center((4 * size) - 3, '-'))


def print_rangoli3(size):
    '''another method'''
    alpha = string.ascii_lowercase  # returns string 'a to z'

    for num in list(range(size))[::-1] + list(range(1, size)):
        print('-'.join(alpha[size - 1:num:-1] + alpha[num:size])
              .center((4 * size) - 3, '-'))


def main():
    '''inside main'''
    num_range = int(input())
    print_rangoli3(num_range)


if __name__ == "__main__":
    main()
