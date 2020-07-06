#!/usr/bin/env python

import pandas


def first_example():
    df = pandas.read_csv('hrdata.csv')
    print(df)


def second_example():
    df = pandas.read_csv('hrdata.csv',
                         index_col='Name',
                         parse_dates=['Hire Date'])
    print(df)


def third_example(filename):
    df = pandas.read_csv(filename,
                         index_col='Employee',
                         parse_dates=['Hired'],
                         header=0,
                         names=[
                             'Employee',
                             'Hired',
                             'Salary',
                             'Sick Days'
                         ])
    print(df)


def write_with_pandas():
    df = pandas.read_csv('hrdata.csv',
                         index_col='Employee',
                         parse_dates=['Hired'],
                         header=0,
                         names=[
                             'Employee',
                             'Hired',
                             'Salary',
                             'Sick Days'
                         ])
    df.to_csv('hrdata_modified.csv')


# second_example()
third_example('hrdata.csv')
write_with_pandas()
third_example('hrdata_modified.csv')
