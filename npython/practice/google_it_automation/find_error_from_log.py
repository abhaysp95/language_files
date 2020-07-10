#!/usr/bin/env python3

'''
find error inputed by user
'''

import os
import re
import sys


def error_search(log_file):
    error = input('What is the error? \n')
    returned_errors = []
    with open(log_file, mode='r', encoding='UTF-8') as file:
        for log in file.readlines():
            error_patterns = ["error"]
            for i in range(len(error.split(' '))):
                error_patterns.append(r"{}".format(
                    error.split(' ')[i].lower()
                ))
            # if all the keyword inside of error_patterns are found by
            # re.search in a log.lower() line then apped that log line to
            # returned_errors
            if all(re.search(error_pattern, log.lower())
                   for error_pattern in error_patterns):
                returned_errors.append(log)
    return returned_errors


def file_output(returned_errors):
    path = '/Documents/npython/practice/google_it_automation/journaldev/errors_found.log'
    with open(os.path.expanduser('~') +
              path,
              'w') as file:
        for error in returned_errors:
            file.write(error)


def file_read():
    path = '/Documents/npython/practice/google_it_automation/journaldev/errors_found.log'
    with open(os.path.expanduser('~') +
              path,
              'r') as file:
        for line in file:
            print(line.strip())


if __name__ == "__main__":
    log_file = sys.argv[1]
    returned_errors = error_search(log_file)
    file_output(returned_errors)

    choice = input('Want to see the result log file[yes or no]: ')
    if choice == 'yes':
        file_read()
    print('EXITING')
