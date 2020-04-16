#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-11
Description: print elements which are not common in all sets
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-11
"""


# main function <<<
def main():
    '''Entering main function'''
    init_lst = []
    count = int(input('Enter the count of sets: '))

    init_lst = [input() for _ in range(count)]

    mid_lst = []
    mid_lst = [init_lst[i].split() for i in range(count)]

    init_set = set(mid_lst[0])
    for i in range(1, count):
        init_set = init_set.intersection(mid_lst[i])

    res_set = set()
    for i in range(count):
        for j in mid_lst[i]:
            res_set.add(j)

    res_set = res_set.difference(init_set)

    for i in sorted(res_set):
        print(i)
# >>>


if __name__ == "__main__":
    print(main.__doc__)
    main()
