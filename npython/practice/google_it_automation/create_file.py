#!/usr/bin/env python3

import os
import sys

dirname = sys.argv[1]
filename = sys.argv[2]


def create_file():
    with open(os.path.join(dirname, filename), 'w') as file:
        pass


# check for directory
print('Checking for entered directory')
if not os.path.exists(dirname):
    print('Directory doesn\'t exist')
    print('Creating New directory')
    os.mkdir(dirname)
elif not os.path.isdir(dirname):
    print('Directory to this name doesn\'t exist')
    print('Creating New directory')
    os.mkdir(dirname)
else:
    print('Directory to this name already exist')

# check for file
print('Checking for file')
if not os.path.exists(os.path.join(dirname, filename)):
    print('File to this filename doesn\'t exists')
    print('Creating an empty file')
    create_file()
    # sys.exit(0)  default exit status on being successful
elif not os.path.isfile(os.path.join(dirname, filename)):
    print('File with this filename doesn\'t exists')
    print('Creating an empty file')
    create_file()
else:
    print('Error, the file {} already exists in {} folder'.format(dirname, filename))
    sys.exit(1)
