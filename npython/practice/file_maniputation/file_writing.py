#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
basic file write operation
"""


def main():
    '''in main function'''
    file = open('file.txt', 'w')

    file.write('''This is from file write operation
''')

    file.write('I\'m learing how to write a script\n'
               'This is how we do it')
    file.close()


if __name__ == "__main__":
    main()
