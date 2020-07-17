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

    # Download the file over the internet(no need)
    response = requests.get(url, stream=True)
    lines = []

    for line in response.iter_lines():
        lines.append(line.decode("UTF-8"))
    return lines
    # with open(filename, 'r') as file:
    #     file_csv = csv.reader(file)
    #     for row in file_csv:
    #         lines.append(','.join(row))
    # return lines

def get_same_or_newer(start_date, data):
    """Returns the employees that started on the given date, or the closest one."""
    reader = csv.reader(data[1:])
    lista = list(reader)
    lista.sort(key=lambda x: x[3])
    min_date = datetime.datetime.today()
    min_date_employees = []
    # my_data = {}
    for row in lista:
        row_date = datetime.datetime.strptime(row[3], '%Y-%m-%d')

        # date = datetime.datetime.strptime(row[3], '%Y-%m-%d')
        # value = "{} {}".format(row[0], row[1])
        # if not (date in my_data.keys()):
            # my_data[date] = [value]
        # add a if block to check for if the value of that particular
        # date already exists
        # if value not in my_data[date]:
            # my_data[date].append(value)
    # sorted_dict = sorted(my_data.keys())
    # for key in sorted_dict:
        # if key < start_date:
            # print("Started on {}: {}".format(key.strftime("%b %d, %Y"), my_data[key]))
        # return sorted_dict

        if row_date < start_date:
            continue
        if row_date < min_date:
            min_date = row_date
            min_date_employees = []
        if row_date == min_date:
            min_date_employees.append("{} {}".format(row[0], row[1]))

    return min_date, min_date_employees

def list_newer(start_date, data):
    while start_date < datetime.datetime.today():
        start_date, employees = get_same_or_newer(start_date, data)
        print("Started on {}: {}".format(start_date.strftime("%b %d, %Y"), employees))

        # Now move the date to the next one
        start_date = start_date + datetime.timedelta(days=1)


def main():
    # download_file(FILE_URL)
    data = get_file_lines(FILE_URL)
    start_date = get_start_date()
    list_newer(start_date, data)
    # get_same_or_newer(start_date, data)


if __name__ == "__main__":
    main()
