#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
wrap the given string according to given width
"""

import textwrap as tw


def wrap(string, max_width):
    '''function to wrap string'''
    row = len(string) // max_width
    if len(string) % max_width > 0:
        row += 1

    for count in range(0, len(string), max_width):
        print(string[count:count + max_width])


def wrap2(string, max_width):
    '''second function to wrap string'''
    para = tw.wrap(string, max_width)
    # return tw.fill(para, width=4)
    return '\n'.join(map(str, para))


def main():
    '''inside main function'''
    print('Enter the string and then maxwidth: ')
    string, max_width = input(), int(input())
    # wrap(string, max_width)
    result = wrap2(string, max_width)
    print(result)


if __name__ == "__main__":
    main()
