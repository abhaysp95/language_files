#!/usr/bin/env python3

'''
open selected title's url through provided browser
'''


# TODO: find the way to suppress the ouput thrown into the console

import sys
import subprocess

class OpenWithQuteBrowser:
    '''open URL with qutebrowser'''

    def __init__(self, url=None):
        self.url = url
        self.name = "QuteBrowser"

    def openBrowser(self):
        if self.url is None:
            print("No URL provided")
            print('Exiting !!!')
            sys.exit(2)
        else:
            try:
                print("URL opening in %s" % self.name)
                # if a browser session is running open in next tab
                # (not another session or window)
                output = subprocess.run(
                    ['qutebrowser', '--target=tab', self.url],
                    stdout=subprocess.DEVNULL, check=True)
            except subprocess.ChildProcessError:
                print("Error, can't open %s" % self.name)
                print("Exiting !!!")
                sys.exit(2)


class OpenWithChromium(OpenWithQuteBrowser):
    ''' open url with chromium browser '''

    def __init__(self, url=None):
        super().__init__(url)
        self.name = "Chromium"

    def openBrowser(self):
        if self.url is None:
            print("No URL provided")
            print('Exiting !!!')
            sys.exit(2)
        else:
            try:
                print("URL opening in %s" % self.name)
                # by default, chromium opens in new tab if a browser session is running
                output = subprocess.run(
                    ['chromium', self.url],
                    stdout=subprocess.DEVNULL, check=True)
            except subprocess.ChildProcessError:
                print("Error, can't open %s" % self.name)
                print("Exiting !!!")
                sys.exit(2)


class OpenWithBrave(OpenWithQuteBrowser):
    ''' open url with brave browser '''

    def __init__(self, url=None):
        super().__init__(url)
        self.name = "brave"

    def openBrowser(self):
        if self.url is None:
            print("No URL provided")
            print('Exiting !!!')
            sys.exit(2)
        else:
            try:
                print("URL opening in %s" % self.name)
                # by default, brave opens in new tab if a browser session is running
                output = subprocess.run(
                    ['brave', self.url],
                    stdout=subprocess.DEVNULL, check=True)
            except subprocess.ChildProcessError:
                print("Error, can't open %s" % self.name)
                print("Exiting !!!")
                sys.exit(2)


class OpenWithVivaldi(OpenWithQuteBrowser):
    ''' open url with vivaldi browser '''

    def __init__(self, url=None):
        super().__init__(url)
        self.name = "Vivaldi-Stable"

    def openBrowser(self):
        if self.url is None:
            print("No URL provided")
            print('Exiting !!!')
            sys.exit(2)
        else:
            try:
                print("URL opening in %s" % self.name)
                # by default, vivaldi opens in new tab if a browser session is running
                output = subprocess.run(
                    ['vivaldi-stable', self.url],
                    stdout=subprocess.DEVNULL, check=True)
            except subprocess.ChildProcessError:
                print("Error, can't open %s" % self.name)
                print("Exiting !!!")
                sys.exit(2)


class Browser:
    ''' open provided browser '''

    def __init__(self, browser='qutebrowser', url=None):
        self.browser = browser
        self.browserObj = None
        self.url = url

    def openSelectedBrowser(self):
        if self.browser == 'qutebrowser':
            self.browserObj = OpenWithQuteBrowser(self.url)
            self.browserObj.openBrowser()
        elif self.browser == 'chromium':
            self.browserObj = OpenWithChromium(self.url)
            self.browserObj.openBrowser()
        elif self.browser == 'brave':
            self.browserObj = OpenWithBrave(self.url)
            self.browserObj.openBrowser()
        elif self.browser == 'vivaldi':
            self.browserObj = OpenWithVivaldi(self.url)
            self.browserObj.openBrowser()
