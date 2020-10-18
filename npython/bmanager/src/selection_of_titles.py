#!/usr/bin/env python3

from os import path
import json
import subprocess

class ReadTitles:
    '''read titles through files'''

    def __init__(self):
        self.__bFilePath__ = path.expanduser('~') + "/.config/test_bookmarks.json"
        self.__bdata__ = dict()

    def getBookMarkDict(self):
        with open(self.__bFilePath__) as bfile:
            self.__bdata__ = json.load(bfile)
        return self.__bdata__


class WithRofi:
    '''selection of title with Rofi'''

    def __init__(self):
        self.selectedTitle = None
        readTitleObj = ReadTitles()
        self.__bDict__ = readTitleObj.getBookMarkDict()

    def openLauncher(self):
        '''open rofi and get selection'''
        try:
            self.selectedTitle = subprocess.run(
                ['rofi', '-dmenu', '-i', '-matching fuzzy', '-p "Select Title:"'],
                input="\n".join(self.__bDict__.keys()),
                text=True, capture_output=True, check=True)
        except subprocess.CalledProcessError as cpe:
            print("You haven't selected any title to perform action upon")
            print("Exiting !!!")
        else:
            self.selectedTitle = self.selectedTitle.stdout.rstrip()
            print("From Rofi:\nTitle: %s\nURL: %s" %
                  (self.selectedTitle, self.__bDict__[self.selectedTitle]))


class WithFzf(WithRofi):
    '''selection with fzf'''

    def __init__(self):
        super().__init__()

    def openLauncher(self):
        '''open fzf and get selecton'''
        try:
            self.selectedTitle = subprocess.run(
                ['fzf', '--prompt', 'Select Title: ', '--border', 'sharp',
                 '--height', '55%'],
                input="\n".join(self.__bDict__.keys()),
                text=True, stdout=subprocess.PIPE, check=True)
                # capture_output doesn't works with fzf
        except subprocess.CalledProcessError as cpe:
            print("You haven't selected any title to perform action upon")
            print("Exiting !!!")
        else:
            self.selectedTitle = self.selectedTitle.stdout.rstrip()
            print("From FZF:\nTitle: %s\nURL: %s" %
                  (self.selectedTitle, self.__bDict__[self.selectedTitle]))


class WithDmenu(WithRofi):
    '''selection with dmenu'''

    def __init__(self):
        super().__init__()

    def openLauncher(self):
        '''open and get selection'''
        try:
            self.selectedTitle = subprocess.run(
                ['dmenu', '-l', '20', '-p', "Select Title:"],
                input="\n".join(self.__bDict__.keys()),
                text=True, capture_output=True, check=True)
        except subprocess.CalledProcessError as cpe:
            print("You haven't selected any title to perform action upon")
            print("Exiting !!!")
        else:
            self.selectedTitle = self.selectedTitle.stdout.rstrip()
            print("From FZF:\nTitle: %s\nURL: %s" %
                  (self.selectedTitle, self.__bDict__[self.selectedTitle]))


class TitlesWithLauncher:
    '''open title with provided launchers'''

    def __init__(self, launcher='fzf'):
        self.launcher = launcher
        self.launcherObj = None

    def openLauncher(self):
        if self.launcher == 'rofi':
            self.launcherObj = WithRofi()
            self.launcherObj.openLauncher()
        elif self.launcher == 'fzf':
            self.launcherObj = WithFzf()
            self.launcherObj.openLauncher()
        elif self.launcher == 'dmenu':
            self.launcherObj = WithDmenu()
            self.launcherObj.openLauncher()


if __name__ == "__main__":
    print("This file isn't meant to run individually")
    print("Exiting !!!")
