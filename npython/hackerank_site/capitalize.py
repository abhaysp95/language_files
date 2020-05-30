#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
capitalize the string
"""


def solve(got_str):
    '''function to capitalize string'''
    str_list = got_str.split(' ')

    for count, words in enumerate(str_list):
        str_list[count] = words.capitalize()
    return ' '.join(str_list)


def solve2(got_str):
    '''another method'''
    str_list = got_str.split(' ')
    return (' '.join(word.capitalize()) for word in str_list)


def solve3(got_str):
    '''third method'''
    for word in got_str[:].split(' '):
        got_str = got_str.replace(word, word.capitalize())
    return got_str


def solve4(got_str):
    '''fourth method'''
    str_list = [got_str.replace(word, word.capitalize())
                for word in got_str.split(' ')]
    return ' '.join(str_list)


def main():
    '''inside main function'''
    res_str = solve3(input())
    print(res_str)


if __name__ == "__main__":
    main()
