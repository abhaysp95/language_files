#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
get hash value of tuple
"""


def main():
    '''inside main function'''
    # count = int(input())  # unnecessary
    print('Enter the space seperated elements: ')
    # lst = list(input().split(' '))
    lst = list(map(int, input().split()))
    tup = tuple(lst)
    print(hash(tup))


if __name__ == "__main__":
    main()
