#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
program to valid strings for differentmethods
"""


def string_validation(string):
    '''function to string validation'''
    ifalnum = False
    ifalpha = False
    ifdigit = False
    iflower = False
    ifupper = False

    for char in string:
        if char.isalnum():
            ifalnum = True
        if char.isalpha():
            ifalpha = True
        if char.isdigit():
            ifdigit = True
        if char.islower():
            iflower = True
        if char.isupper():
            ifupper = True

    print(ifalnum)
    print(ifalpha)
    print(ifdigit)
    print(iflower)
    print(ifupper)


def string_validation2(string):
    '''function for string validation(trying any)'''
    ifalnum = any(c.isalnum() for c in string)
    ifalpha = any(c.isalpha() for c in string)
    ifdigit = any(c.isdigit() for c in string)
    iflower = any(c.islower() for c in string)
    ifupper = any(c.isupper() for c in string)
    print(ifalnum)
    print(ifalpha)
    print(ifdigit)
    print(iflower)
    print(ifupper)


def main():
    '''inside main function'''
    # string_validation2(input())
    string_validation2('qA2')


if __name__ == "__main__":
    main()
