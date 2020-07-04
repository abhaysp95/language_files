#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
learning about defaultdict
"""

from collections import defaultdict


def main():
    '''inside main function'''
    adict = {
        5: 'five',
        6: 'six',
        7: 'seven'}
    print(adict)
    adict.setdefault(1, 'one')  # sets permanently to dict
    adict.setdefault(6, 'SIX')
    adict.get(2, 'two')  # doesn't set permanently to dict
    adict.get(5, 'FIVE')
    print(adict)

    issubclass(defaultdict, dict)
    alst = list(adict)
    print(alst)
    def_dict = defaultdict(tuple)
    def_dict[2] = 'two'
    def_dict['missing']
    # def_dict['another_missing'].append('ten')
    def_dict['another_missing'] += tuple(def_dict)
    def_dict['missing'] += (3, 4, 5)
    print(def_dict)


if __name__ == "__main__":
    main()
