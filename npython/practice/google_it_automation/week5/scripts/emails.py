#!/usr/bin/env python3

'''
read a csv file and store it's content to dictionary
'''

import csv
import sys


def fill_dictionary(filename):
    '''fillup the dictionary from csv file'''
    email_dictionary = dict()
    with open(filename, 'r') as file:
        email_file = csv.reader(file, delimiter=',')
        for row in email_file:
            name = row[0].lower()
            email_dictionary[name] = row[1]
    return email_dictionary


def get_email(arguments):
    '''get the email'''
    # you can also check the len of arguments to be 3
    # instead of try block
    try:
        got_name = arguments[1] + ' ' + arguments[2]
        email_dictionary = fill_dictionary("../data/user_emails.csv")
        # you can also use if-else block instead of
        # try-except in here
        try:
            return email_dictionary[got_name.lower()]
        except KeyError:
            return "Provided name isn't present in the file"
    except IndexError:
        return "Provided arguments are not enough"


def main():
    '''main function'''
    print(get_email(sys.argv))


if __name__ == "__main__":
    main()
