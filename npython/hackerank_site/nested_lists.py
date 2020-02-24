#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-23
Description: Nested list creation and find second last
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-23
"""

if __name__ == "__main__":
    #n = int(input())
    lst = [[input(), float(input())] for _ in range(int(input()))]
    #print(lst)
    lst.sort()
    # lst1 = []
    # lst1 = sorted(lst)[1]
    # print(lst)
    # sec_highest = sorted(list(set([marks for name, marks in lst])))[1]
    # print('\n'.join([a for a, b in sorted(lst) if b == sec_highest]))
    sec_lowest = sorted(lst, key = lambda x:x[1])
    print(type(sec_lowest))
    lst1 = []
    for i in range(1, len(sec_lowest) - 1):
        lst1.append(sec_lowest[1])
        if sec_lowest[1] != sec_lowest[i + 1]:
            break
    # print(*lst1, sep='\n')
    #print(lst1)
    print(*lst1, sep=' ')
