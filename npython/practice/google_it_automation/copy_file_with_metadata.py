#!/usr/bin/env python3

'''
copy files with metadata
'''

import os
import shutil
import time


def file_metadata(file_name):
    stat_info = os.stat(file_name)
    print('\tMode     : ', oct(stat_info.st_mode))
    print('\tCreated  : ', time.ctime(stat_info.st_ctime))
    print('\tAccessed : ', time.ctime(stat_info.st_atime))
    print('\tModified : ', time.ctime(stat_info.st_mtime))


if not os.path.exists('journaldev'):
    os.mkdir('journaldev')
print('Source File: ')
if not os.path.exists('file_copy.txt') or not os.path.isfile('file_copy.txt'):
    file_md = open('file_copy.txt', 'w')
    file_md.write('This is for metadata example only')
    file_md.close()

file_metadata('file_copy.txt')
# if you want to make exact clone along with permissions
# and metadata of the file use copy2()
shutil.copy2('file_copy.txt', 'journaldev/file_copy.txt')
print('Destination File: ')
file_metadata('file_copy.txt')
