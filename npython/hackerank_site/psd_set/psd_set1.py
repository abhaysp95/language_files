#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-10
Description: If any one element in common in listed sets
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-10
"""


# creating main function <<<
def main():
    '''Entering main function'''
    count = int(input('Enter the count for row: '))

    init_lst = [input() for _ in range(count)]

    mid_lst = [init_lst[i].split() for i in range(len(init_lst))]

    # length = 0
    # for i, _ in enumerate(mid_lst):
    #     length = length + len(mid_lst[i])

    # main_set = set()
    # for i, _ in enumerate(mid_lst):
    #     for j in mid_lst[i]:
    #         main_set.add(j)

    # if length > len(main_set):
    #     print('True')
    # else:
    #     print('False')

    res_set = set(mid_lst[0])

    for i in range(count):
        res_set = res_set.intersection(mid_lst[i])

    if len(res_set) > 0:
        print('True')
        print('Common elements are: ')

        # since, sets can't be sliced, so change into list/tuple
        res_tuple = tuple(res_set)
        for i, _ in enumerate(res_tuple):
            print(res_tuple[i])
    else:
        print('False')
# >>>


if __name__ == "__main__":
    print(main.__doc__)
    main()
