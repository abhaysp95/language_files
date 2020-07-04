#!/usr/bin/python3.8

"""
Author: Abhay Shanker Pathak
Date: 2020-04-22
Description: handling matrix with numpy module
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-22
"""

import numpy


# function to insert values for matrix <<<
def read_matrix(matrix_name, rows, columns):
    '''reading values'''
    for _ in range(rows):
        child_matrix = []
        for _ in range(columns):
            print("> ", end=' ')
            child_matrix.append(int(input()))
        matrix_name.append(child_matrix)

# >>>


# function to perform airthmetic operations on matrix <<<
def do_op_on_matrix(first_matrix, second_matrix, got_op_name):
    '''performing arithmetic operations on matrix'''
    matrix_a = numpy.array(first_matrix)
    matrix_b = numpy.array(second_matrix)

    if got_op_name == 'add':
        print(numpy.add(matrix_a, matrix_b))
    elif got_op_name == 'subtract':
        print(numpy.subtract(matrix_a, matrix_b))
    elif got_op_name == 'multiply':
        print(numpy.multiply(matrix_a, matrix_b))
    elif got_op_name == 'divide':
        print(numpy.divide(matrix_a, matrix_b))
# >>>


# function to get the name of operation <<<
# this function is unnecessary, just used for purpose of learning
def get_op_name():
    '''getting the name of operation'''
    print(''' Enter the operation number:
            1: add
            2: subtract
            3: multiply
            4: divide''')
    entered_num = int(input())
    names = {
        1: 'add',
        2: 'subtract',
        3: 'multiply',
        4: 'divide'
    }
    sel_name = names.get(entered_num)
    return sel_name
# >>>


# main function <<<
def main():
    '''Entering in main function'''

    # reading first matrix
    rows = int(input('Enter the number of rows for first matrix: '))
    columns = int(input('Enter the number of columns for first matrix: '))

    first_matrix = []
    print(read_matrix.__doc__)
    print("Insert values of rows and columns for first matrix: ")
    read_matrix(first_matrix, rows, columns)

    # reading second matrix
    rows = int(input('Enter the number of rows for second matrix: '))
    columns = int(input('Enter the number of columns for second matrix: '))

    second_matrix = []
    print(read_matrix.__doc__)
    print("Insert values of rows and columns for first matrix: ")
    read_matrix(second_matrix, rows, columns)

    # operations on matrix
    got_name = get_op_name()
    do_op_on_matrix(first_matrix, second_matrix, got_name)
# >>>


if __name__ == "__main__":
    print(main.__doc__)
    main()
