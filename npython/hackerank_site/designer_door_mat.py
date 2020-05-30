#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
make a designer dor mat with |, ., and - characters and a WELCOME in between
"""


def long_method(height, width):
    '''function to get door mat'''
    # upper body
    for num in range(height // 2):
        print('-' * (((width - 3) // 2) - 3 * num), end='')
        print('.|.' * (num + 1), end='')
        print('.|.' * (num), end='')
        print('-' * (((width - 3) // 2) - 3 * num))

    # middle belt
    print('WELCOME'.center(width, '-'))

    # lower body
    for num in range(height // 2):
        print('-' * (3 + (3 * num)), end='')
        print('.|.' * ((height // 2) - num), end='')
        print('.|.' * ((height // 2) - (num + 1)), end='')
        print('-' * 3 * (num + 1))


def another_method(height, width):
    '''another method to get doormat'''
    for num in range(height // 2):
        print(('.|.' * (2 * num + 1)).center(width, '-'))
    print('WELCOME'.center(width, '-'))
    for num in range(height // 2):
        print(('.|.' * ((2 * (height // 2) - 1) - (2 * num)))
              .center(width, '-'))


def third_method(height, width):
    '''third method to get door mat'''
    pattern = [(('.|.' * (2 * num + 1)).center(width, '-'))
               for num in range(height // 2)]
    pattern = [('\n'.join(pattern + ['WELCOME'.center(width, '-')]
                          + pattern[::-1]))]
    print('\n'.join(pattern))


def main():
    '''main and designer function'''
    height, width = map(int, input('Enter height then width: ').split(' '))
    # long_method(height, width)
    third_method(height, width)


if __name__ == "__main__":
    main()
