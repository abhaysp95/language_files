#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-05
Description: using class for module importuserclass.py
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-05
"""

import importuserclass


def main():
    '''Inside main function'''
    new_admin = importuserclass.Admin_User('dk', 'yes', '3:45', '4:39',
                                           'can remove other users')
    new_admin.describe_user()
    new_admin.get_privilege.show_privileges()


if __name__ == "__main__":
    main()
