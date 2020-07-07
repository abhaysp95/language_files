#!/usr/bin/env python3

'''
change high domain abc.edu to xyz.edu
'''

import csv
import re
from os import path


def domain_matches(address, domain):
    '''check if the domain matches to abc.edu'''
    pattern = r"[\w\.-]+@" + domain + "$"
    if re.match(pattern, address):
        return True
    return False


def change_domain(address, old_domain, new_domain):
    '''change abc.edu to xyz.edu'''
    pattern = r'' + old_domain + '$'
    new_address = re.sub(pattern, new_domain, address)
    return new_address


def main():
    '''change the address from a csv file'''
    old_domain = 'abc.edu'
    new_domain = 'xyz.edu'

    # lists to put email addresses accordingly
    user_email_list = list()
    old_user_address = list()
    new_user_address = list()

    main_folder = '/home/raytracer/Documents/npython/practice'
    sec_folder = '/google_it_automation/regex/data'
    file_path = main_folder + sec_folder + '/user_emails.csv'
    updated_file_path = main_folder + sec_folder + '/updated_user_emails.csv'
    # just to be sure
    if not path.isfile(file_path):
        if not path.exists(file_path):
            print('File doesn\'t exists in the given path')
            exit()
        print('The given path hasn\'t file of the given name')
        exit()

    # read email
    with open(file_path, 'r') as file:
        email_file = list(csv.reader(file))
        user_email_list = [data[1].strip() for data in email_file[1:]]

        # change email if matches
        for email in user_email_list:
            if domain_matches(email, old_domain):
                old_user_address.append(email)
                new_email = change_domain(email, old_domain, new_domain)
                new_user_address.append(new_email)

        email_key = ' Email Address'
        email_index = email_file[0].index(email_key)

        # update with new_domain
        for user in email_file[1:]:
            for old_email, new_email in zip(old_user_address,
                                            new_user_address):
                if user[email_index] == ' ' + old_email:
                    user[email_index] = ' ' + new_email

    # write in the file
    with open(updated_file_path, 'w+') as file:
        updated_file = csv.writer(file)
        updated_file.writerows(email_file)

    print('Domain Updated Successfully')


if __name__ == "__main__":
    main()


# if_domain_matches('univeristy.done@abc.edu', 'abc.edu')
# change_domain('univeristy.done@abc.edu', 'abc.edu', 'xyz.edu')
