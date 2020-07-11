#!/usr/bin/env python

'''
change all the given extension file to another extension
'''

import os
import re
import subprocess
import sys


def get_content(old_extension, path='.'):
    '''get the contents of dir'''
    sep = os.path.sep
    all_content = os.listdir(path)
    # print('get_content: ', path)
    files_list = [content for content in all_content
                  if os.path.isfile(path + sep + content)]
    pattern = r"" + old_extension + "$"
    desired_files = [file for file in files_list
                     if re.search(pattern, file)]
    if len(desired_files) == 0:
        # return "No file found with given old extension"
        raise RuntimeError("There's no file with the given old extension")
    return desired_files


def change_name(new_extension):
    '''change the extensions now'''
    rel_path = '.'
    sep = os.path.sep
    try:
        rel_path = sys.argv[1]
        files = get_content(input('Enter old extension: '), rel_path)
    except IndexError:
        files = get_content(input('Enter old extension: '))

    for file in files:
        pattern = r"(.*)\..*$"
        file_new = re.sub(pattern, r"\1." + new_extension, file)
        file = rel_path + sep + file
        file_new = rel_path + sep + file_new
        subprocess.run(["mv", file, file_new], check=True)
    print('Renaming Successful')


def main():
    '''main function'''
    try:
        if sys.argv[1] == "-h":
            print("Usage: ./change_extensions [RELATIVE_PATH]")
            sys.exit()
        if sys.argv[1] != '':
            change_name(input('Enter new extension: '))
    except IndexError:
        print('No additional argument provided.')
        print('Considering current folder to make changes')
        change_name(input('Enter new extension: '))


if __name__ == "__main__":
    main()
