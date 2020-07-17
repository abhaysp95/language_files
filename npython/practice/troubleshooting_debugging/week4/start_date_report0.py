#!/usr/bin/env python3


import csv
import datetime
import requests


FILE_URL = "https://storage.googleapis.com/gwg-hol-assets/gic215/employees-with-date.csv"

def get_start_date():
    """Interactively get the start date to query for."""

    print()
    print('Getting the first start date to query for.')
    print()
    print('The date must be greater than Jan 1st, 2018')
    year = int(input('Enter a value for the year: '))
    month = int(input('Enter a value for the month: '))
    day = int(input('Enter a value for the day: '))
    print()

    return datetime.datetime(year, month, day)

def get_file_lines(url):
    """Returns the lines contained in the file at the given URL"""

    # Download the file over the internet
    response = requests.get(url, stream=True)
    lines = []

    for line in response.iter_lines():
        lines.append(line.decode("UTF-8"))
    return lines

# def sorted_data(data):
#     """provides a sorted list"""
#     reader = csv.reader(data[1:])
#     list_sort = list(reader)
#     list_sort.sort(key=lambda x: x[3])
#     return list_sort

def get_same_or_newer(start_date, data):
    """Returns the employees that started on the given date, or the closest one."""
    # data = get_file_lines(FILE_URL)
    # lista = list(reader)
    # lista.sort(key=lambda x: x[3])
    reader = csv.reader(data[1:])
    data_dict = dict()


    # min_date = datetime.datetime.today()
    # min_date_employees = []
    for row in reader: 
        row_date = datetime.datetime.strptime(row[3], '%Y-%m-%d')
        fullname = "{} {}".format(row[0], row[1])
        if start_date <= row_date:
            if row_date not in data_dict.keys():
                data_dict[row_date] = [fullname]
            if fullname not in data_dict[row_date]:
                data_dict[row_date].append(fullname)
    # sorting the data_dict
    sorted_data_dict = sorted(data_dict.keys())
    # print(sorted_data_dict)
    for key in sorted_data_dict:
        print("Started on {}: {}".format(key.strftime("%b %d, %Y"), data_dict[key]))

        # if row_date < start_date:
        #     continue
        # if row_date < min_date:
        #     min_date = row_date
        #     min_date_employees = []
        # if row_date == min_date:
        #     min_date_employees.append("{} {}".format(row[0], row[1]))

    # return min_date, min_date_employees

# def list_newer(start_date, data):
#     # data = sorted_data(data)
#     while start_date < datetime.datetime.today():
#         start_date, employees = get_same_or_newer(start_date, data)
#         print("Started on {}: {}".format(start_date.strftime("%b %d, %Y"), employees))
# 
#         # Now move the date to the next one
#         start_date = start_date + datetime.timedelta(days=1)

def main():
    start_date = get_start_date()
    data = get_file_lines(FILE_URL)
    # list_newer(start_date, data)
    get_same_or_newer(start_date, data)

if __name__ == "__main__":
    main()
