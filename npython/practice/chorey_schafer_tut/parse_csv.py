#!/usr/bin/env python3

import csv

with open('./names.csv', 'r') as csv_file:
    read_file = csv.reader(csv_file)

    # next(read_file)  # skipping first line

    with open('new_names.csv', 'w') as new_file:
        csv_writer = csv.writer(new_file, delimiter='\t')

        for line in read_file:
            # print(line[2])
            csv_writer.writerow(line)

with open('./new_names.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter='\t')
    for line in csv_reader:
        print(line)


# with dictionary
with open('names.csv', 'r') as csv_file:
    csv_reader = csv.DictReader(csv_file)

    with open('new_names.csv', 'w') as new_file:
        fieldnames = ['first_name', 'last_name'] # removing email
        csv_writer = csv.DictWriter(new_file, fieldnames=fieldnames, delimiter='\t')
        csv_writer.writeheader()
        for line in csv_reader:
            # print(line['email'])
            del line['email']
            csv_writer.writerow(line)
