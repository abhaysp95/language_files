#!/usr/bin/env python

import os
import datetime

def file_date(filename):
    with open(filename, 'w') as file:
        pass

    timestamp = os.path.getmtime(filename)
    new_time = datetime.datetime.fromtimestamp(timestamp)
    # print(type(str(new_time)))
    new_time = str(new_time)
    return ("{:.10}".format(new_time))

print(file_date("newfile.txt"))
