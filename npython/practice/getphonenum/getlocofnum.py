#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-04
Description: Get location of number
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-04
"""

import phonenumbers
from phonenumbers import geocoder
from phonenumbers import carrier
from pnum import number

ch_nmber = phonenumbers.parse(number, 'CH')
# gives location
print(geocoder.description_for_number(ch_nmber, "en"))

service_nmber = phonenumbers.parse(number, "RO")
print(carrier.name_for_number(service_nmber, "en"))
