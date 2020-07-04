#!/usr/bin/env python

import os

def parent_directory():
    # you can also use os.pardir which is basically '..'
    relative_parent = os.path.join(os.getcwd(), '..')
    relative_parent = os.path.abspath(relative_parent)
    return relative_parent


print(parent_directory())
