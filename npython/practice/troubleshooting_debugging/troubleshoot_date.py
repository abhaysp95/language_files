#!/usr/bin/env python3

import datetime
from datetime import date


def add_year(date_obj):
    try:
        new_date_obj = date_obj.replace(year=date_obj.year + 1)
    except ValueError:
        # if the above one fails, which means we are making leap year
        new_date_obj = date_obj.replace(year=date_obj.year + 4)
    return new_date_obj


def next_date(date_string):
    # convert the argument from string to datetime object
    date_obj = datetime.datetime.strptime(date_string, r"%Y-%m-%d")
    next_date_obj = add_year(date_obj)

    # convert the datetime object to string
    # next_date_string = next_date_obj.strftime("yyyy-mm-dd")
    # above line was the issue
    next_date_string = next_date_obj.strftime("%Y-%m-%d")
    return next_date_string


today = date.today()  # Get today's date
print(next_date(str(today)))
# should return a year from today, unless today is Leap Day

print(next_date("2021-01-01"))  # Should return 2022-01-01
print(next_date("2020-02-29"))  # Should return 2024-02-29
