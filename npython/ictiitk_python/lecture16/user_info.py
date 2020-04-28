#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-26
Description: building user profile, example of arbitrary keword arguments
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-26
"""


# function for profile building <<<
def build_profile(first_name, last_name, **user_info):
    '''building a dictionary containing everything we know about a user'''
    print(type(user_info))
    print(user_info)
    user_info['first_name'] = first_name
    user_info['last_name'] = last_name
    return user_info
# >>>


# main function <<<
def main():
    '''Entering in main function'''
    user_profile = build_profile('Rahul', 'Garg', location='IITKanpur',
                                 field='ICT')
    print(user_profile)
# >>>


if __name__ == "__main__":
    main()
