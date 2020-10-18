#!/usr/bin/env python3

import argparse
import sys
import os

from src import parse_bookmarks
from src import selection_of_titles

class ExtTools:
    '''deals with external things of project'''

    def __init__(self, selector='fzf', browser=os.getenv('BROWSER')):
        self.parser = argparse.ArgumentParser()
        self.selector = selector
        self.browser = browser

    def make_arguments(self):
        self.group1 = self.parser.add_mutually_exclusive_group()
        self.group1.add_argument('-s', '--selector', type=str, metavar='rofi|fzf',
                                 choices=['rofi', 'fzf'], help='use rofi or fzf for selection')

        # self.inner_group1 = self.group1.add_mutually_exclusive_group()  # this group is not allowed with -s/--selector
        # self.inner_group1.add_argument('-i', '--ice', action='store_true', help='delete bookmark')
        # self.inner_group1.add_argument('-j', '--king', type=str, metavar='Browser', help='select browser')
        # self.inner_group1.add_argument('-k', '--joker', action='store_true', help='update bookmarks')

        self.group2 = self.parser.add_mutually_exclusive_group()
        self.group2.add_argument('-d', '--delete', action='store_true', help='delete bookmark')
        self.group2.add_argument('-b', '--browser', type=str,
                                 choices=['chromium', 'vivaldi', 'brave', 'qutebrowser'],
                                 metavar='Browser', help='select browser')
        self.group2.add_argument('-u', '--update', action='store_true', help='update bookmarks')
        self.args = self.parser.parse_args()

    def process_args(self):
        if self.args.selector:
            self.selector = self.args.selector
            if self.args.browser:
                # open url with given browser
                self.browser = self.args.browser
                print('open with ' + self.browser)
            elif self.args.update:
                # update url
                print("Warning: No need to use selector flag for updating")
                updateBookmark = parse_bookmarks.WriteNewBookmarks()
                updateBookmark.updateBookmarks()
            elif self.args.delete:
                # delete selected url
                print('delete with ' + self.selector)
            else:
                # open url with default browser using given selector
                print('select operation to perform: \nselector: %s, browser: %s' % (self.selector, self.browser))
        elif self.args.browser:
            # open url using default selector with given browser
            self.browser = self.args.browser
            print('open url with ' + self.browser + ' using ' + self.selector)
        elif self.args.update:
            # update url with default selector
            updateBookmark = parse_bookmarks.WriteNewBookmarks()
            updateBookmark.updateBookmarks()
        elif self.args.delete:
            # delete url with default selector
            print('delete with ' + self.selector)
        else:
            # open url with default selector in default browser
            print('select url: \nusing selector: %s, browser: %s' % (self.selector, self.browser))


ext = ExtTools()
ext.make_arguments()
ext.process_args()
