#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
performing different list operations given by user
"""


# here are the commands:
# Consider a list (list = []). You can perform the following commands:
# insert i e: Insert integer e at position .
# print: Print the list.
# remove e: Delete the first occurrence of integer e.
# append e: Insert integer e at the end of the list.
# sort: Sort the list.
# pop: Pop the last element from the list.
# reverse: Reverse the list.

PROMPT = '> '


def main():
    '''inside main function'''
    print('Enter the number: \n')
    num = int(input(PROMPT))

    alist = []
    for _ in range(num):
        command, *number = input().split()
        num_list = list(map(int, number))
        if command == 'insert':
            alist.insert(num_list[0], num_list[1])
        elif command == 'print':
            print(alist)
        elif command == 'remove':
            alist.remove(num_list[0])
        elif command == 'append':
            alist.append(num_list[0])
        elif command == 'sort':
            alist.sort()
        elif command == 'pop':
            alist.pop()
        elif command == 'reverse':
            alist.reverse()


if __name__ == "__main__":
    main()
