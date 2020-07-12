#!/usr/bin/env python3

'''
stdin, stdout, stderr from shell
'''


data = input('This will come from STDIN: ')
print = ('This will be written to STDOUT: ', data)
raise ValueError('Now we generate an error to STDERR')
