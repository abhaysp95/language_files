#!/usr/bin/env python3


''' delete provided title and url '''

import json
from sys import exit
from os import path


class DeleteBMark:
    ''' delete provided bmark '''

    def __init__(self, title=None):
        self.gotTitle = title
        self.oDict = dict()
        self.bPath = path.expanduser('~') + '/.config/test_bookmarks.json'

    def __openAndDel__(self):
        try:
            with open(self.bPath, 'r') as jfile:
                self.oDict = json.load(jfile)
            removedURL = self.oDict.pop(self.gotTitle, 'Nothing')
            if removedURL != 'Nothing':
                print('Removed\nTitle: %s\nand\ncorresponding URL: %s'
                      % (self.gotTitle, removedURL))
            else:
                print("Title not found or not provided")
                print("Try Again !")
                exit(2)
        except FileNotFoundError as ffe:
            print("Bookmark file not found: " + ffe)

    def __write__(self):
        try:
            with open(self.bPath, 'w') as jfile:
                json.dump(self.oDict, jfile, indent=4)
        except FileNotFoundError:
            print("File not found to write, no updatation after deletion performed")
            exit(2)

    def delete(self):
        DeleteBMark.__openAndDel__(self)
        DeleteBMark.__write__(self)
