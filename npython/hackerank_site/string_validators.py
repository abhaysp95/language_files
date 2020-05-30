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
    print(string.isalnum())
    print(string.isalpha())
    print(string.isdigit())
    print(string.islower())
    print(string.isupper())


def main():
    '''inside main function'''
    string_validation(input())


if __name__ == "__main__":
    main()
