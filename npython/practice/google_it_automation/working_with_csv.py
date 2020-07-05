#!/usr/bin/env python3

import csv

def read_csv(filename):
    '''read a csv file'''
    with open(filename, 'r') as file:
        # reader method will interpret file like csv
        csvf = csv.reader(file)
        for row in csvf:
            first, second, third = row
            print("{} , {} , {}".format(first, second, third))


def write_csv():
    '''write to a csv file'''
    distro_info = [[input('name: '), input('pac_man: '), input('parent: ')]
                   for _ in range(3)]
    with open('distro_info.csv', 'w') as distcsv:
        distcsv = csv.writer(distcsv)
        # there's also writerow() method
        distcsv.writerows(distro_info)


def read_csv_dict(filename):
    '''read csv file as dictionary'''
    keys = [input('column: ') for _ in range(3)]
    with open(filename, 'r') as file:
        csvfd = csv.DictReader(file)
        for row in csvfd:
            # print(row.keys())
            print("{} , {} , {}"
                  .format(row[keys[0]], row[keys[1]], row[keys[2]]))


def write_csv_dict():
    '''write data to a csv file in form of dictionary'''
    info = [{'name': input('name: '),
             'username': input('username: '),
             'department': input('department: ')} for _ in range(3)]
    with open('employee_info.csv', 'w') as file:
        got_keys = list(info[0].keys())
        # fieldnames parameter is optional, by default, first column of a csv
        # file is considered as fieldname
        emp_csv = csv.DictWriter(file, fieldnames=got_keys)
        emp_csv.writeheader()
        emp_csv.writerows(info)


print('Simple reading:')
read_csv('student_info.csv')
print('\nGive Distro Info: ')
write_csv()
print('\nReading Distro Info:')
read_csv('distro_info.csv')
print('\nRead Student info in dictionary form:')
read_csv_dict('student_info.csv')
print('\nWrite employee information:')
write_csv_dict()
print('\nReading employee info in dictionary format: ')
read_csv_dict('employee_info.csv')
