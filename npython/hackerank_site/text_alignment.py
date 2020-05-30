#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
text alignment operation design an H
"""


def main():
    '''inside main function'''
    thickness = int(input('Enter the odd number: '))
    char = 'H'

    # top cone
    for num in range(thickness):
        # print((char*num).rjust(thickness - 1, '-') + char
        # + (char*num).ljust(thickness - 1, '-'))
        print((char*num).rjust(thickness - 1) + char
              + (char*num).ljust(thickness - 1))

    # top pillar
    for _ in range(thickness + 1):
        print((char*thickness).center(thickness * 2)
              + (char*thickness).center(thickness * 6))

    # middle belt
    for _ in range((thickness + 1) // 2):
        print((char * thickness * 5).center(thickness * 6))

    # bottom pillar
    for _ in range(thickness + 1):
        print((char * thickness).center(thickness*2)
              + (char * thickness).center(thickness * 6))

    # bottom cone
    for num in range(thickness):
        print(((char * (thickness - num - 1)).rjust(thickness) + char
               + (char * (thickness - num - 1)).ljust(thickness))
              .rjust(thickness * 6))


if __name__ == "__main__":
    main()
