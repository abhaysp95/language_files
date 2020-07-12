#!/usr/bin/env python3

'''
use with retry.sh
'''

import sys
import random

value = random.randint(0, 8)
print('Returning ' + str(value))
sys.exit(value)
