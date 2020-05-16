#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
Implementing selection sort in python
"""


def minimum(got_lst, initial):
    '''returns the location of minimum value on a iteration'''
    loc = initial
    initial += 1
    while initial < len(got_lst):
        if got_lst[loc] > got_lst[initial]:
            loc = initial
        initial += 1
    return loc


def swap_min(got_lst, first, second):
    '''swap minimum value with first point'''
    if got_lst[first] != got_lst[second]:
        got_lst[first] = got_lst[first] + got_lst[second]
        got_lst[second] = got_lst[first] - got_lst[second]
        got_lst[first] = got_lst[first] - got_lst[second]


def main():
    '''Inside main function'''
    given_lst = []
    print('Enter the elements: ')
    for _ in range(int(input())):
        given_lst.append(int(input()))
    print('list before selection sort is: ')
    print(given_lst)

    for num in range(len(given_lst) - 1):
        min_index = minimum(given_lst, num)
        swap_min(given_lst, num, min_index)

    print('list after selection sort is: ')
    print(given_lst)


if __name__ == "__main__":
    main()
