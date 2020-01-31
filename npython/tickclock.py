#!/usr/bin/env python

"""
File: tickclock.py
Author: abhay
Email: abhaysp9955@email.com
Github: https://github.com/yourname
Description:
"""

from time import sleep
import time

while 1:
    print(time.strftime("%H:%M:%S"))
    sleep(1)    # from time module
