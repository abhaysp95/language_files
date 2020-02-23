#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-23
Description: Print second largest element
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-23
"""

if __name__ == "__main__":
    n = int(input('Enter the count: '))
    arr = map(int, input().split())
    lst = list(arr)
    # sorting list
    lst.sort()
    max = lst[0]
    sec_max = max
    # sorted list
    print(lst)
    # find second largest element
    for i in range(0, n):
        if max < lst[i]:
            sec_max = max
            max = lst[i]
    print(sec_max)
