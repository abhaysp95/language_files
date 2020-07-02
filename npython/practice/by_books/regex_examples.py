#!/usr/bin/env python

'''
examples of regex
'''

import re


def firstExample(fhand):
    for line in fhand:
        if re.search('From: ', line):
            print(line, end='')


def secondExample(fhand):
    for line in fhand:
        if re.search('F..m: ', line):
            print(line, end='')


def thirdExample(fhand):
    for line in fhand:
        if re.search('F..m:.+@', line):
            print(line, end='')


def fourthExample(fhand):
    '''get email'''
    for line in fhand:
        email = re.findall(r'\S+@\S+', line)
        if len(email) == 0:
            continue
        print(''.join(email))


def fifthExample(fhand):
    '''get email'''
    for line in fhand:
        line = line.rstrip()
        email = re.findall(r'[a-zA-z0-9]\S+@\S*[a-zA-Z].[a-zA-Z]+$', line)
        if len(email) == 0:
            continue
        print(''.join(email))


def sixthExample(fhand):
    '''get floating numbers'''
    for line in fhand:
        line = line.rstrip()
        # gives object of noneType
        # if () used within regular expression, they are ignored
        if re.search(r'^X-.*:\s([0-9.0-9]+)', line):
            # print(''.join(number))
            print(line)


def seventhExample(fhand):
    '''extract floating numbers'''
    for line in fhand:
        line = line.rstrip()
        flnum = re.findall(r'^X-.*:\s([0-9.0-9]+$)', line)
        if len(flnum) == 0:
            continue
        # changing in string from list
        print(''.join(flnum))


def eighthExample(fhand):
    '''extract urls containg revision number'''
    url_list = list()
    for line in fhand:
        # if re.search(r'Details:\s.*&rev=[0-9]+$', line):
        # print(line)
        rev_number = re.findall(r'Details:\s(.*&rev=[0-9]+?$)', line)
        if len(rev_number) == 0:
            continue
        print(''.join(rev_number))
        url_list.append(''.join(rev_number))
    return url_list


def ninthExample(url_list):
    '''extract revision numbers from the urls with help of regex'''
    for url in url_list:
        flnum = re.findall(r'\S+rev=([0-9]+?)$', url)
        print(''.join(flnum))


def tenthExample(fhand):
    '''get hour of mail sent'''
    for line in fhand:
        hour = re.findall(r'^From\s.*\s([0-9]+):.*', line)
        if len(hour) == 0:
            continue
        print(''.join(hour))


# some other regex expressions are
# *?, +?, ?, ??, [aeiou], [a-z0-9], [^A-za-z], \b, \B, \d, \D = [^0-9]


def main():
    '''inside main function'''
    try:
        file_handler = open('mbox-short.txt', 'r')
    except:
        print('File not found')
        exit()

    print('First example')
    firstExample(file_handler)
    print()
    file_handler.seek(0, 0)

    print('Second example')
    secondExample(file_handler)
    print()
    file_handler.seek(0, 0)

    print('Third example')
    thirdExample(file_handler)
    print()
    file_handler.seek(0, 0)

    print('Fourth example')
    fourthExample(file_handler)
    print()
    file_handler.seek(0, 0)

    print('Fifth example')
    fifthExample(file_handler)
    print()
    file_handler.seek(0, 0)

    print('Sixth example')
    sixthExample(file_handler)
    print()
    file_handler.seek(0, 0)

    print('Seventh example')
    seventhExample(file_handler)
    print()
    file_handler.seek(0, 0)

    print('Eighth example')
    url_list = eighthExample(file_handler)
    print()
    file_handler.seek(0, 0)

    print('Ninth example')
    ninthExample(url_list)
    print()
    file_handler.seek(0, 0)

    print('Tenth example')
    tenthExample(file_handler)
    print()
    file_handler.seek(0, 0)

    file_handler.close()


if __name__ == "__main__":
    main()
