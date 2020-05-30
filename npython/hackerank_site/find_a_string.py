#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
get the count of substring inside a string
"""


def count_substring(string, substring):
    '''function to count substring'''
    start = string.find(substring)
    count = 0
    if start != -1:
        count = 1
    else:
        return count
    # for _ in range(start + 1, len(string)):
    # print(start)
    # start = string.find(substring, start + 1)
    # if start:
    # count += 1
    # using range, range fixes the elements, so changing start inside loop
    # will not change the range thing, so if starting range is (3, 7) and
    # num give 3, 4, 5, 6, so changing start will not make num give 3, 5, 6
    while count < len(string):
        start = string.find(substring, start + 1)
        # you can also provie end range after the initial range for find func
        if start == -1:
            break
        count += 1
    return count


# another method
def count_substring2(string, substring):
    '''function to count substring using list comprehesion'''
    return sum(1 for num in range(len(string) - len(substring) + 1)
               if string[num:num + len(substring)] == substring)


def main():
    '''inside main function'''
    string = input().strip()
    substring = input().strip()
    count = count_substring2(string, substring)
    print(count)


if __name__ == "__main__":
    main()
