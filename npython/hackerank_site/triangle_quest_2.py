#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
get palindrome triangle for given number
"""


def main():
    '''inside main function'''
    count = int(input())
    for num in range(1, count + 1):
        for num1 in range(1, num + 1):
            print(num1, end='')
        if num > 1:
            for num2 in range(num - 1, 0, -1):
                print(num2, end='')
        print()

    print('Another method')
    for num in range(1, count + 1):
        print(((10 ** num - 1) // 9) ** 2)


if __name__ == "__main__":
    main()
