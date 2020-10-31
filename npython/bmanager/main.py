#!/usr/bin/env python3

# TODO: if browser instance isn't always running, it takes up the terminal.
# Find a way to deal with this problem

import argparse
import sys
import os

from src import parse_bookmarks
from src import selection_of_titles
from src import open_through_browser
from src import delete_bookmarks

class ExtTools:
    '''deals with external things of project'''

    def __init__(self, selector='fzf', browser=os.getenv('BROWSER')):
        self.parser = argparse.ArgumentParser()
        self.selector = selector
        self.browser = browser
        self.gotTitle = None
        self.gotURL = None

    def make_arguments(self):
        self.group1 = self.parser.add_mutually_exclusive_group()
        self.group1.add_argument('-s', '--selector', type=str, metavar='rofi|fzf|dmenu',
                                 choices=['rofi', 'fzf', 'dmenu'], help='use rofi, fzf or dmenu for selection')

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
                gotTitles = selection_of_titles.TitlesWithLauncher(self.selector)
                self.gotTitle, self.gotURL = gotTitles.openLauncher()
                self.browser = self.args.browser
                print('opening with ' + self.browser)
                browserObj = open_through_browser.Browser(self.browser, self.gotURL)
                browserObj.openSelectedBrowser()
            elif self.args.update:
                # update url
                print("Warning: No need to use selector flag for updating")
                updateBookmark = parse_bookmarks.WriteNewBookmarks()
                updateBookmark.updateBookmarks()
            elif self.args.delete:
                # delete selected url
                print('deleting with ' + self.selector)
                gotTitles = selection_of_titles.TitlesWithLauncher(self.selector)
                self.gotTitle, self.gotURL = gotTitles.openLauncher()
                delBMark = delete_bookmarks.DeleteBMark(self.gotTitle)
                delBMark.delete()
            else:
                # open url with default browser using given selector
                print('select with %s and open in default browser %s' % (self.selector, self.browser))
                gotTitles = selection_of_titles.TitlesWithLauncher(self.selector)
                self.gotTitle, self.gotURL = gotTitles.openLauncher()
                browserObj = open_through_browser.Browser(self.browser, self.gotURL)
                browserObj.openSelectedBrowser()
        elif self.args.browser:
            # open url using default selector with given browser
            self.browser = self.args.browser
            print('open url with ' + self.browser + ' using default selector ' + self.selector)
            gotTitles = selection_of_titles.TitlesWithLauncher(self.selector)
            self.gotTitle, self.gotURL = gotTitles.openLauncher()
            browserObj = open_through_browser.Browser(self.browser, self.gotURL)
            browserObj.openSelectedBrowser()
        elif self.args.update:
            # update url with default selector
            updateBookmark = parse_bookmarks.WriteNewBookmarks()
            updateBookmark.updateBookmarks()
        elif self.args.delete:
            # delete url with default selector
            print('deleting with ' + self.selector)
            gotTitles = selection_of_titles.TitlesWithLauncher(self.selector)
            self.gotTitle, self.gotURL = gotTitles.openLauncher()
            delBMark = delete_bookmarks.DeleteBMark(self.gotTitle)
            delBMark.delete()
        else:
            # open url with default selector in default browser
            print('select with default selector %s and open in default browser %s' % (self.selector, self.browser))
            gotTitles = selection_of_titles.TitlesWithLauncher()
            self.gotTitle, self.gotURL = gotTitles.openLauncher()
            browserObj = open_through_browser.Browser(self.browser, self.gotURL)
            browserObj.openSelectedBrowser()


if __name__ == "__main__":
    ext = ExtTools()
    ext.make_arguments()
    ext.process_args()


# set up obj for launchers in appropriate place
