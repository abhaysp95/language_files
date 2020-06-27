#!/usr/bin/env python

import chap9_ex3

def get_max_mail(fname):
    got_dict = chap9_ex3.get_dict(fname)

    max_num = sorted(got_dict.values())[-1]

    for key in got_dict:
        # if got_dict[key] == max_num:
        if got_dict.get(key) == max_num:
            print('{}: {}'.format(key, max_num))


get_max_mail(input('Enter the filename: '))
