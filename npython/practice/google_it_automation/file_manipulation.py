#!/usr/bin/env python3

import os
from datetime import datetime

file = open('test_file.txt', 'r')
print(file.readline())
print(file.readline())
print(file.readlines())
file.seek(0, 0)  # puts cursor position at starting in file

print(file.read())

file.close()
# if you forget to close file, use 'with'

print('Using with')
with open('test_file.txt', 'r') as file:
    print(file.readline())
# using with, python automatically closes at the end of block

with open('test_file.txt', 'r') as file:
    for line in file:
        # print(repr(line))
        # print(line, end='')
        print(line.strip().upper())

file = open('test_file.txt', 'r')
lines = file.readlines()
lines.sort()
print(lines)
file.close()


# write in file
with open('new_write.txt', 'w') as file:
    # if file doesn't exist python will create it
    # other mods are:
    # a = append
    # b = binary mode
    # t = text mode(default)
    # + = open for updating(read-write)
    file.write('This is the first line written')
    # when successfully written this method returns number of character wrote

with open('new_write.txt', 'r') as file:
    print(file.read())

# using os module

os.rename('new_write.txt', 'latest_write.txt')

# os.path submodule(check whether the file exists)
print(f'if file exists: {os.path.exists("latest_write.txt")}')
print(f'if file exists: {os.path.exists("new_write.txt")}')
print(f'OS name: {os.name}')

if not os.path.exists('new_osdir'):
    os.mkdir('new_osdir')
print(os.path)
print(f'check if directory exists: {os.path.exists("new_osdir")}')
print('Removing files and directories')
os.remove('latest_write.txt')
os.removedirs('new_osdir')

print('size of file is: %d' % os.path.getsize('test_file.txt'))

if not os.path.exists('test_dir'):
    os.mkdir('test_dir')
with open('./test_dir/under_file.txt', 'w') as file:
    file.write('A file under a new_directory')

print('size of folder is: %d' % os.path.getsize('test_dir'))

# file when modified

print(f'Time since timestamp: {os.path.getmtime("test_file.txt")}')
timestamp = os.path.getmtime("test_file.txt")
# timestamp method of datetime class, imported from datetime module
print(f'In human format: {datetime.fromtimestamp(timestamp)}')

print('checking isfile: ', os.path.isfile('test_file.txt'))

# gives absoulte path
print(f'Absolute path is: {os.path.abspath("test_file.txt")}')

# current working directory
print(f'Current directory: {os.getcwd()}')
if os.path.exists('test_dir'):
    os.chdir('test_dir')
    print(f'Current directory: {os.getcwd()}')

os.chdir('../')
print(f'Current directory: {os.getcwd()}')
# give directory name which you want in place of '.', this shows for curdir
print(f'Content of this directory is: {os.listdir(".")}')

isfile_dict = dict()

for content in os.listdir(os.getcwd()):
    # in here join() method is plateform independent to join (/, \)
    abspath = os.path.join(os.getcwd(), content)
    # print(abspath)
    isfile_dict[abspath] = os.path.isdir(abspath)

print('Type of content in the given directory:\n')
for key, value in isfile_dict.items():
    print('{}: {}'.format(key, value))
