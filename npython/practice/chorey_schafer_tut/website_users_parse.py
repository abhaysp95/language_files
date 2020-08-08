#!/usr/bin/env python3

'''
parse the website_users.csv
'''

import csv

html_output = ''
names = []

with open('website_users.csv', 'r') as data_file:
    csv_data = csv.DictReader(data_file)

    # skip the first line of bad data
    next(csv_data)

    for line in csv_data:
        if line['FirstName'] == 'No Reward':
            break
        names.append(f"{line['FirstName']} {line['LastName']}")

print(f"<p>There are currently {len(names)} contributors. Thank You!</p>")

html_output+="<ul>"

for name in names:
    html_output+=f"\n\t<li>{name}</li>"

html_output+='\n</ul>'

print(html_output)
