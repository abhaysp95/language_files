#!/usr/bin/env python3

import subprocess


def get_hostname():
    print('Enter the command with "host <ip>": ')
    command = input().split()
    result = subprocess.run(command, capture_output=True)
    print(result.stdout.decode('UTF-8'))  # or else it just literally converts binary
    # UTF-8 is default
    if result.stderr.decode() == '':
        print('No Errors')
    else:
        result.stderr.decode()


def rm_file():
    print('Remove file command that doesn\'t exist, "rm <filename>": ')
    command = input().split()
    # if you want to exit out on failure of run, use check=True
    result = subprocess.run(command, capture_output=True)
    print(result.stdout.decode())
    print(result.stderr.decode())
    print('Exit Code: ', result.returncode)


print('First Function: \n')
get_hostname()
print('Second Function: \n')
rm_file()
