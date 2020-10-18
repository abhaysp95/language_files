#!/usr/bin/env python3

import os
from os import path
import json


'''
put the name with url in a centralized bookmark file
'''

class ParseBookmarks:
    '''get bookmarks from different browsers bookmarks file'''

    def __init__(self):
        self.__newBDict__ = dict()

    def __updateChromium__(self):
        '''get bookmarks for Chromium Browser'''
        bpath = path.expanduser('~') + '/.config/chromium/Default/Bookmarks'
        try:
            with open(bpath, 'r') as bfile:
                bdata = json.load(bfile)
            dataset = bdata['roots']['bookmark_bar']['children']
            for data in dataset:
                self.__newBDict__[data['name']] = data['url']
        except FileNotFoundError:
            print("Bookmark file for Chromium not found")

    def __updateBrave__(self):
        '''get bookmarks for Brave Browser'''
        bpath = path.expanduser('~') + '/.config/BraveSoftware/Brave-Browser/Default/Bookmarks'
        try:
            with open(bpath, 'r') as bfile:
                bdata = json.load(bfile)
            dataset = bdata['roots']['bookmark_bar']['children']
            for data in dataset:
                self.__newBDict__[data['name']] = data['url']
        except FileNotFoundError:
            print("Bookmark file for Brave not found")

    def __updateVivaldi__(self):
        '''get bookmarks for Vivaldi Browser'''
        bpath = path.expanduser('~') + '/.config/vivaldi/Default/Bookmarks'
        try:
            with open(bpath, 'r') as bfile:
                bdata = json.load(bfile)
            dataset = bdata['roots']['bookmark_bar']['children'][0]['children']
            for data in dataset:
                if 'url' in data.keys():
                    self.__newBDict__[data['name']] = data['url']
        except FileNotFoundError:
            print("Bookmark file for Vivaldi not found")

    def __updateQuteBrowser__(self):
        '''get bookmarks for qutebrowser'''
        bpath = path.expanduser('~') + "/.config/qutebrowser/bookmarks/urls"
        try:
            with open(bpath, 'r') as bfile:
                lines = bfile.read().splitlines()
                for line in lines:
                    ssplit = line.split(' ')
                    self.__newBDict__[' '.join(ssplit[1:])] = ssplit[0]
        except FileNotFoundError:
            print("Bookmark(urls) file for QuteBrowser not found")

    def bmarkDict(self):
        '''parse bookmarks from every browsers bookmark file and return dictionary'''
        ParseBookmarks.__updateChromium__(self)
        ParseBookmarks.__updateBrave__(self)
        ParseBookmarks.__updateVivaldi__(self)
        ParseBookmarks.__updateQuteBrowser__(self);
        return self.__newBDict__;

class WriteNewBookmarks:
    '''write bookmarks to centeralized local bookmark file'''

    def __init__(self):
        self.__newBmarkLocation__ = path.expanduser('~') + '/.config/test_bookmarks.json'
        self.__totalBmarkDict__ = dict()
        print("Updating Bookmarks")

    def __checkIfFileExists__(self):
        '''check if file and parent folders exist or not'''
        basedir = path.dirname(self.__newBmarkLocation__)
        if not path.exists(basedir):
            try:
                os.makedirs(basedir)
            except OSError as e:
                print('Path already exists: ' + e)
        if not path.exists(self.__newBmarkLocation__):
            with open(self.__newBmarkLocation__, 'a'):
                os.utime(self.__newBmarkLocation__, None)

    def __writeToFile__(self):
        '''write total got bookmarks to centralized bookmark file in json format'''
        parseBmarksObj = ParseBookmarks()
        self.__totalBmarkDict__ = parseBmarksObj.bmarkDict()
        with open(self.__newBmarkLocation__, 'w') as jfile:
            json.dump(self.__totalBmarkDict__, jfile, indent=4)

    def updateBookmarks(self):
        '''finally updatation'''
        WriteNewBookmarks.__checkIfFileExists__(self)
        WriteNewBookmarks.__writeToFile__(self)
