#!/usr/bin/env python3

import os
import shutil
import pprint

# copytree function takes input that must not exist before the running command
def replicate_tree():
    shutil.copytree('../google_it_automation', './new_journaldev')
    print('After:')
    pprint.pprint(os.listdir('./new_journaldev'))


def remove_tree():
    print('Before: ')
    # content of current directory, new_journal dev exists in this folder
    pprint.pprint(os.listdir('.'))
    shutil.rmtree('./new_journaldev')
    # new_journaldev is deleted, it's already recursive deletion
    print('After: ')
    pprint.pprint(os.listdir('.'))


remove_tree()
