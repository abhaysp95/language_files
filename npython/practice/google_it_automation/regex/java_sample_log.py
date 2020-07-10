#!/usr/bin/env python3

import re
import sys
import csv

filename = sys.argv[1]
list_log = list()
error_type_count = dict()

print('Getting the data')
with open(filename, 'r') as file:
    for line in file:
        line = line.strip()
        if not line.startswith('java'):
            continue
        pattern = r"\[([A-Z]+)\].*\s(\d+)$"
        result = re.search(pattern, line)
        # print("Type: {}\tid: {}".
        # format(result.groups()[0], result.groups()[1]))

        list_log.append({
            'ID': result[2],
            'TYPE': result[1]
        })

        # count the type of error
        error_type_count[result[1]] = error_type_count.get(
            result[1],
            0
        ) + 1


# writing to the log file
print('\nWriting log file to "journaldev/java_logid.csv"')
with open('../journaldev/java_logid.csv', 'w') as file:
    heading = ["ID", "TYPE"]
    logfile = csv.DictWriter(
        file,
        fieldnames=heading
    )
    logfile.writeheader()
    logfile.writerows(list_log)


# reading the log file
print('\nReading log file from "journaldev/java_logid.csv"')
with open('../journaldev/java_logid.csv') as file:
    readfile = csv.DictReader(file)
    for row in readfile:
        print("{}\t{}".format(
            row[heading[0]],
            row[heading[1]]
        ))


print("\nCount of Errors:")
for key in error_type_count:
    print("{}: {}".format(key, error_type_count[key]))
