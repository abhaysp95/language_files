#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
in given string do string split and join
"""


def split_and_join(line):
    '''function to split and join'''
    line = line.split(' ')
    new_line = '-'.join(line)
    return new_line


def main():
    '''inside main function'''
    line = input('Enter the line: ')
    result_line = split_and_join(line)
    print(result_line)


if __name__ == "__main__":
    main()
