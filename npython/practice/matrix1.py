#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-22
Description: using matrix in python
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-22
"""

# two ways to handle matrix:
# 1. list
# 2. numpy module, it gives add(), subtract(), divide() & multiply() methods


# main function <<<
def main():
    '''entering in main function'''
    rows = int(input("Enter number of rows: "))
    columns = int(input("Enter number of columns: "))

    # list for matrix
    mat_list = []

    # entering values
    for i in range(rows):
        child_mat_lst = []
        for j in range(columns):
            child_mat_lst.append(int(input()))
        mat_list.append(child_mat_lst)

    # print result matrix
    print('The result matrix is: ')
    for i in range(rows):
        for j in range(columns):
            print(mat_list[i][j], end='\t')
        print()
# >>>


if __name__ == "__main__":
    print("main.__doc__")
    main()
