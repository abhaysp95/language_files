#!/usr/bin/env python3

import random

participants = ['Jack','Jill','Larry','Tom']
new_participants = ['Cathy', 'Fred', 'Jack', 'Tom']


def guess(ppts):
    ppts_dict = {}
    for participant in ppts:
        ppts_dict[participant] = random.randint(1, 9)
    # if ppts_dict['Larry'] == 9:
        # return True
    # else:
        # return False
    try:
        ppts_dict['Larry'] == 9
    except KeyError:
        return 'Key for the given dictionary not found'


print(guess(new_participants))
