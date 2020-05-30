#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
print decimal, octal, hex, binary
"""


def print_formatted(number):
    '''function to write number in all four formats'''
    width = len(bin(number))

    for num in range(1, number + 1):
        print('{}'.format(num).rjust(width), end='')
        print('{}'.format(oct(num)[2:]).rjust(width), end='')
        print('{}'.format(hex(num)[2:]).rjust(width), end='')
        print('{}'.format(bin(num)[2:]).rjust(width))


def print_formatted2(number):
    '''same as print_formatted'''

    for num in range(1, number + 1):
        # b = binary, x = hex(lower), d = decimal, o = octal, X = hex(upper)
        # c = char(gives unicode for int), n = 'same as d, uses current locale
        # settings'
        width = len('{:b}'.format(number)) + 1
        print('{}'.format(num).rjust(len(str(number)) + 1), end='')
        print('{:o}'.format(num).rjust(width), end='')
        print('{:x}'.format(num).rjust(width), end='')
        print('{:b}'.format(num).rjust(width))

    print()

    for num in range(1, number + 1):
        width = len('{:b}'.format(number)) + 1
        print('{}'.format(num).rjust(width - 1), end='')
        print('{:#o}'.format(num)[2:].rjust(width), end='')
        print('{:#x}'.format(num)[2:].rjust(width), end='')
        print('{:#b}'.format(num)[2:].rjust(width))

    print()

    for num in range(1, number + 1):
        width = len('{:b}'.format(number)) + 1
        for base in 'doxb':
            print('{0:{width}{base}}'.format(num, base=base, width=width),
                  end='')
        print()

    print()

    for num in range(1, number + 1):
        print('{0:{width}d} {0:{width}o} {0:{width}x} {0:{width}b}'
              .format(num, width=width))


def main():
    '''inside main function'''
    count = int(input())
    print_formatted2(count)


if __name__ == "__main__":
    main()
