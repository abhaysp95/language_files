#!/usr/bin/env python3

import csv


def read_employees(csv_file_location):
    file = open(csv_file_location, 'r')
    csv.register_dialect(
        'empDialect',
        skipinitialspace=True,
        strict=True)
    employee_file = csv.DictReader(file, dialect='empDialect')

    # creating list to store information
    employee_list = []
    for data in employee_file:
        employee_list.append(data)
    return employee_list

employee_list = read_employees('/home/raytracer/Documents/npython/practice/google_it_automation/week2/data/empolyees.csv')

def process_data(employee_list):
    department_list = list()
    for employee_data in employee_list:
        department_list.append(employee_data['Department'])

    # removing redundancy
    department_data = dict()
    for department_name in set(department_list):
        department_data[department_name] = department_list.count(department_name)
    return department_data

dictionary = process_data(employee_list)

def write_report(dictionary, report_file):
    with open(report_file, 'w+') as rfile:
        for key in sorted(dictionary):
            rfile.write(str(key)+':'+str(dictionary[key])+'\n')


write_report(dictionary, '/home/raytracer/Documents/npython/practice/google_it_automation/week2/data/report.txt')
