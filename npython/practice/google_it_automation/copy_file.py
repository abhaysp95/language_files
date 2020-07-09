#!/usr/bin/env python3

import os
import shutil

with open('filetocopy.txt', 'w') as file:
    file.write('This file for copying only')

os.mkdir('journaldev')
print('Before: ', os.listdir('journaldev'))
shutil.copy('./filetocopy.txt', './journaldev')
print('After: ', os.listdir('journaldev'))
