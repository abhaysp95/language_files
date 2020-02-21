#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-20
Description: given x, y, z and n. print list such that for every
x + y + z != n (got it?)
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-20
"""

if __name__ == "__main__":
    print('Enter x, y, z and n: ')
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    lst = [[i, j, k] for i in range(x + 1) for j in range(y + 1) for k in range(z + 1) if (i + j + k) != n]
    print(lst)
