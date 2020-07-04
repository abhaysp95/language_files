#!/usr/bin/env python

# give dict for days and number of mail msg

def get_dictionary(fname):
    try:
        fhand = open(fname, 'r')
    except:
        print('File %s doesn\'t exist' % fname)
        exit()

    dict_is = dict()
    for line in fhand:
        line = line.rstrip()
        words = line.split()
        if len(words) < 3 or words[0] != 'From':
            continue
        dict_is[words[2]] = dict_is.get(words[2], 0) + 1
    return dict_is


res_dict = get_dictionary(input('Enter the filename: '))
print(res_dict)
