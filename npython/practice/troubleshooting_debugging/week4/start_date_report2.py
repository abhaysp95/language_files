#!/usr/bin/env python3


import csv
import datetime
import requests



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


def get_file_lines(url, start_date):
    """Returns the lines contained in the file at the given URL"""

    # Download the file over the internet
    response = requests.get(url, stream=True)

    data_dict = dict()
    count = 0
    for line in response.iter_lines():
        if count == 0:
            count += 1
            continue
        row = (line.decode("UTF-8")).split(',')
        row_date = datetime.datetime.strptime(row[3], '%Y-%m-%d')
        fullname = "{} {}".format(row[0], row[1])
        if start_date <= row_date:
            if row_date not in data_dict.keys():
                data_dict[row_date] = [fullname]
            if fullname not in data_dict[row_date]:
                data_dict[row_date].append(fullname)
    sorted_data_dict = sorted(data_dict.keys())
    for key in sorted_data_dict:
        print("Started on {}: {}".format(key.strftime("%b %d, %Y"), data_dict[key]))


def main():
    FILE_URL = "https://storage.googleapis.com/gwg-hol-assets"
    FILE_URL += "/gic215/employees-with-date.csv"
    start_date = get_start_date()
    get_file_lines(FILE_URL, start_date)


if __name__ == "__main__":
    main()
