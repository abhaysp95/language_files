#!/usr/bin/env python3

'''
a disk usage script with python
'''

from sys import argv
import os
from rich.console import console


class GetContent():
    '''class to get content'''

    home = os.path.expanduser("~")
    curdir = os.getcwd()

    def __init__(self, flag=None, path=curdir):
        self.path = path
        self.directories = []
        self.files = []

    def get_content(self):
        '''get the content of current directory'''
        contents = os.scandir(self.path)
        return contents

    def differentiate_content(self):
        '''differentiate according to different things'''
        contents = self.get_content()
        for content in contents:
            if content.isdir():
                self.directories.append(content.name)
            else:
                self.files.append(content.name)

    def print_content(self):
        '''print the content'''


def main():
    '''main function'''
    arguments = ["--directories-first", "--colors", "--hidden"]
    try:
        # ls_item = GetContent(argv[1])
        if len(argv) > 2:
# start here
    except IndexError:
        print("No directory or filename provided by user")
        print("Looking in current directory")
        ls_item = GetContent()
    ls_item.get_content()


if __name__ == "__main__":
    main()
