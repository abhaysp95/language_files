#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
get indices of words from a group relative to another
"""

from collections import defaultdict


def first_method():
    '''first method'''
    fnum, snum = [int(x) for x in input().split()]
    agroup = [input() for _ in range(fnum)]
    bgroup = [input() for _ in range(snum)]

    default_agroup = defaultdict(list)

    # indices = [[] * x for x in range(len(bgroup))]
    for count1, element1 in enumerate(bgroup):
        indices = []
        count = False
        for count2, element2 in enumerate(agroup):
            if element1 == element2:
                indices.append(count2 + 1)
                count = True
        if count is False:
            default_agroup[element1].append(-1)
        print(' '.join(map(str, indices)))
        print(' '.join(map(str, default_agroup)))


def second_method():
    '''second method'''
    lst = []
    def_dict = defaultdict(list)
    fnum, snum = map(int, input().strip().split())

    # for count in range(fnum):
    # def_dict[input()].append(str(count+1))
    [def_dict[input()].append(str(count + 1)) for count in range(fnum)]
    print(def_dict)

    lst += [input() for _ in range(snum)]
    print(lst)

    for element in lst:
        if element in def_dict:
            print(' '.join(def_dict[element]))
        else:
            print("-1")


def main():
    '''inside main function'''
    second_method()


if __name__ == "__main__":
    main()
