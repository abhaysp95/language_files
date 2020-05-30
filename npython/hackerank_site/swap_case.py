#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
toggle case
"""


def swap_case(got_string):
    '''function to toggle case'''
    new_string = ''
    for char in got_string:
        if chr(65) <= char <= chr(90):
            new_string += char.lower()
        elif chr(97) <= char <= chr(122):
            new_string += char.upper()
        else:
            new_string += char
    return new_string


def main():
    '''inside main function'''
    get_string = input('Enter the string: ')
    res_str = swap_case(get_string)
    print(res_str)


if __name__ == "__main__":
    main()
