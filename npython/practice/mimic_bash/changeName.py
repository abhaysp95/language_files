#!/usr/bin/env python3

import subprocess
import os

def changeName(oldName, newNameBase):
    temp = oldName.split('.')
    newName = newNameBase
    for index in range(len(temp)):
        if (index != 0):
            newName += temp[index]
        if (index != (len(temp) - 1)):
            newName += '.'
    if os.path.isfile(oldName):
        subprocess.call(["mv", oldName, newName])
    else:
        print("file doesn't exist in path")
    return newName

oldName = 'test.1.2.png'
newName = "new"
print("Changed name from %s to %s " % (oldName, changeName(oldName, newName)))
