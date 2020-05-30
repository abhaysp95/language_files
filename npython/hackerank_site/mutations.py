#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
change string at certain given position
"""


def mutate_string(string, position, character):
    '''function to mutate string'''
    # we could also first change into list then modify and then join
    string = string[:position] + character + string[position + 1:]
    return string


def main():
    '''inside main function'''
    s = input()
    i, c = input().split()
    s_new = mutate_string(s, int(i), c)
    print(s_new)


if __name__ == "__main__":
    main()
