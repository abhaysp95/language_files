#!/usr/bin/env python3

'''
format xxx-xxx-xxxx to (xxx) xxx-xxxx
'''

import re

def convert_phone_number(number):
    result = re.sub(r"(\d{3})-(\d{3}-\d{4}\.?)$", r"(\1) \2", number)
    return result

print(convert_phone_number("My number is 212-345-9999.")) # My number is (212) 345-9999.
print(convert_phone_number("Please call 888-555-1234")) # Please call (888) 555-1234
print(convert_phone_number("123-123-12345")) # 123-123-12345
print(convert_phone_number("Phone number of Buckingham Palace is +44 303 123 7300")) # Phone number of Buckingham Palace is +44 303 123 7300
