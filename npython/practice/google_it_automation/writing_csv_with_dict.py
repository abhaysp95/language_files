#!/usr/bin/env python

import csv

with open('another_employee_file.csv', mode="w") as file:
    header = ["emp_name", "dept", "birth_month"]
    writer = csv.DictWriter(file, fieldnames=header)

    writer.writeheader()
    writer.writerow({
        'emp_name': 'John Smith',
        'dept': 'Sales',
        'birth_month': 'May'
    })
    writer.writerow({
        'emp_name': 'Erica_Meyers',
        'dept': 'IT',
        'birth_month': 'Febraury'
    })
