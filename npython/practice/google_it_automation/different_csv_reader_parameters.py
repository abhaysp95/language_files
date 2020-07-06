#!/usr/bin/env python

import csv
import os

def employee_info(filename):
    with open(filename, 'r') as file:
        # below are different reader options that can be used to parse csv
        csvfile = csv.DictReader(file,
                                 delimiter=',',
                                 quotechar='"',
                                 escapechar='\\')
        line_count = 0
        for row in csvfile:
            if line_count == 0:
                print(f'Column names are {",".join(row)}')
                line_count += 1
            print(f'\t{row["name"]} has username {row["username"]} and works in {row["department"]}.')


fname = input('Enter the filename: ')
if os.path.exists(fname):
    employee_info(fname)
else:
    print('file doesn\'t exist')
