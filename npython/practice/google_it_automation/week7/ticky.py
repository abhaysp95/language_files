#!/usr/bin/env python3

'''
get errors and users
'''

import csv
import re


def get_error_count(filename):
    '''get the count of errors'''
    error_list = list()
    error_dict = dict()
    with open(filename, 'r') as logfile:
        for line in logfile.readlines():
            line = line.strip()
            error = re.search(r"ERROR ([\w ']+) ", line)
            if error is None:
                continue
            error_dict[error.group(1)] = error_dict.get(error.group(1), 0) + 1
    for error, count in error_dict.items():
        error_list.append({"Error": error, "Count": count})
    # or you can use operator.itemgetter("Count")
    error_list = sorted(error_list, key=lambda d: d["Count"], reverse=True)
    return error_list


def get_user_stats(filename):
    '''get the users with there error type counts'''
    user_list = list()
    user_error = dict()
    user_info = dict()
    user_set = set()
    with open(filename, 'r') as logfile:
        for line in logfile:
            line = line.strip()
            match_type = re.search(r":\s([A-Z]+)\s", line)
            user = re.search(r"\(([\w.]+)\)", line)
            user_set.add(user.group(1))
            if match_type.group(1) == "ERROR":
                user_error[user.group(1)] = user_error.get(
                    user.group(1), 0
                ) + 1
            if match_type.group(1) == "INFO":
                user_info[user.group(1)] = user_info.get(
                    user.group(1), 0
                ) + 1
        # print(user_error)
        # print(user_info)
        # print(user_set)
    for username in user_set:
        user_list.append({
            "Username": username,
            "INFO": user_info.get(username, 0),
            "ERROR": user_error.get(username, 0)
        })
    user_list = sorted(user_list, key=lambda d: d["Username"])
    return user_list


def write_to_csv(filename, data, heading):
    '''write the content to the csv file'''
    with open(filename, 'w+') as csvfile:
        error_csvfile = csv.DictWriter(csvfile, fieldnames=heading,
                                       delimiter=',')
        error_csvfile.writeheader()
        error_csvfile.writerows(data)


def main():
    '''main function'''
    source_file = 'syslog.log'
    error_data = get_error_count(source_file)
    error_header = ["Error", "Count"]
    write_to_csv('error_message.csv', error_data[:], error_header[:])
    user_data = get_user_stats(source_file)
    user_header = ["Username", "INFO", "ERROR"]
    write_to_csv('user_statistics.csv', user_data[:], user_header[:])


if __name__ == "__main__":
    main()
