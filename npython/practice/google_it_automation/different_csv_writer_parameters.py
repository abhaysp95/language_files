#!/usr/bin/env python3

import csv

with open('new_employee_file.csv', mode="w") as file:
    # different csv writer modes for quoting are
    # csv.QUOTE_MINIMAl
    # csv.QUOTE_ALl
    # csv.QUOTE_NONNUMERIc
    # csv.QUOTE_NONE
    emp_writer = csv.writer(file,
                            delimiter=',',
                            quotechar='"',
                            quoting=csv.QUOTE_NONNUMERIC)
    emp_writer.writerow(['John Smith, Accounting, 765'])
    emp_writer.writerow(['Erica Meyers, IT, 865'])
