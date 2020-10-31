#!/usr/bin/env python3

import json
from os import path

def getJsonData(bfile):
    '''read json'''
    with open(bfile, 'r') as file:
        data = json.load(file)
    useful_data = dict()
    for bmark in data['roots']['bookmark_bar']['children'][0]['children']:
        if 'url' in bmark.keys():
            useful_data[bmark['name']] = bmark['url']
    for key, value in useful_data.items():
        print(key + "\n\t" + value + "\n")
    print(useful_data)

getJsonData(path.expanduser('~') + '/.config/vivaldi/Default/Bookmarks')

# chromium, Brave are same in storing data as json, Vivaldi is bit different, quteBrowser stores as type of csv(just not c) and also have to check firefox
