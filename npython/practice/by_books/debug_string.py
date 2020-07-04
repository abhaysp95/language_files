#!/usr/bin/env python

def first_method():
    while True:
        line = input('> ')
        if line[0] == '#':
            continue
        # if we give empty line, it'll give string index out of range
        if line == 'done':
            break
        print(line)
    print('Done!')

def second_method():
    while True:
        line = input('> ')
        if line.startswith('#'):
            continue
        if line == 'done':
            break
        print(line)
    print('Done!')

def third_method():
    while True:
        line = input('> ')
        if len(line) > 0 and line[0] == '#':
            continue
        if line == 'done':
            break
        print(line)
    print('Done!')

third_method()
