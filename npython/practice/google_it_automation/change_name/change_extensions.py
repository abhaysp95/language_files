#!/usr/bin/env python

'''
change all the given extension file to another extension
'''

import os
import re
import subprocess


def get_content(old_extension):
    '''get the contents of dir'''
    all_content = os.listdir('.')
    files_list = [content for content in all_content
                  if os.path.isfile(content)]
    pattern = r"" + old_extension + "$"
    desired_files = [file for file in files_list
                     if re.search(pattern, file)]
    if len(desired_files) == 0:
        # return "No file found with given old extension"
        raise RuntimeError("There's no file with the given old extension")
    return desired_files


def change_name(new_extension):
    '''change the extensions now'''
    files = get_content(input('Enter old extension: '))
    for file in files:
        pattern = r"(.*)\..*$"
        file_new = re.sub(pattern, r"\1." + new_extension, file)
        subprocess.run(["mv", file, file_new], check=True)
    print('Renaming Successful')


change_name(input('Enter new extension: '))
