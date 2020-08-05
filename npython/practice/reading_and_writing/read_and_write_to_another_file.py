#!/usr/bin/env python3

with open('../os_walks.py', 'r') as read_file:
    with open('os_walks.txt', 'w') as write_file:
        for line in read_file:
            write_file.write(line)
