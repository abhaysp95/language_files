#!/usr/bin/env python3

import subprocess
import sys
import os


# run a Bash command and send output to a list seperated by line
def runBash(cmd):
    p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
    out = p.stdout.read().strip()
    # return out.split('\n')  # this will not work because out is binary type not str
    # so two ways, either give b'\n' or decode out to str type first
    return out.decode('utf-8').split('\n')

# change name function
def changeName(oldName, newNameBase):
    temp = oldName.split('.')
    newName = newNameBase
    for index in range(len(temp)):
        if index != 0:
            newName += temp[index]
        if index != (len(temp) - 1):
            newName += '.'
    print("%s -> %s" % (oldName, newName))
    subprocess.call(["mv", oldName, newName])


# change names of all files matching base
def changeAllNames(oldNameBase, newNameBase):
    files = runBash("ls")
    for file in files:
        if file.split('.')[0] == oldNameBase:
            changeName(file, newNameBase)


# change files with base test to base new
def main():
    try:
        if (sys.argv[1]):
            if os.path.exists(sys.argv[1]):
                try:
                    os.chdir(sys.argv[1])
                    changeAllNames("test", "new")
                except FileNotFoundError:
                    print("Given path doesn't exist in this directory")
            else:
                raise NameError("Path provided not found")
    except IndexError:
        print("Provide folder name/path")
    except NameError as ne:
        print(ne)


if __name__ == "__main__":
    main()

