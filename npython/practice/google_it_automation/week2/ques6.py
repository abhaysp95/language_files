#!/usr/bin/env python3

'''
create, write and read
'''

import os
import csv

def create_file(filename):
    with open(filename, 'w') as file:
        file.write("name,color,type\n")
        file.write("carnation,pink,annual\n")
        file.write("daffodil,yellow,perennial\n")
        file.write("iris,blue,perennial\n")
        file.write("poinsettia,red,perennial\n")
        file.write("sunflower,yellow,annual\n")

# read the file contents function to create the file
def contents_of_file(filename):
    return_string = ""
    create_file(filename)
    line_count = 0

    # open and read file
    with open(filename, 'r') as file:
        rows = csv.reader(file)
        for row in rows:
            name, color, types = row
            if line_count != 0:
                return_string += "a {} {} is {}\n".format(
                    color, name, types)
            line_count += 1
    return return_string


print(contents_of_file("flowers2.csv"))
