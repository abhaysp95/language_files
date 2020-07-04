#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-17
Description: importing and using date time module
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-17
"""

from datetime import datetime

odds = ['1', '3', '5', '7', '9', '11', '13', '15', '17', '19', '21', '23', '25', '27', '29', '31', '33', '35', '37', '39', '41', '43', '45', '47', '49', '51', '53', '55', '57', '59']

right_this_minute = datetime.today().minute()

if right_this_minute in odds:
    print("This minute seems a little odd.")
else:
    print("Not an odd minute.")
