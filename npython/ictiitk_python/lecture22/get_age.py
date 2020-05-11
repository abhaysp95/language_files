#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
get the age of the person
"""


import datetime


class Birthdate():
    '''enter birthdate in format of yyyy mm dd'''
    # don't enter 0 before, if day is 03 then enter 3

    def __init__(self, get_date=None):
        self.bday = get_date

    def inputdate(self):
        '''get date in proper form'''
        if __name__ == '__main__':
            year, month, day = map(int, self.bday.split(', '))
            return datetime.date(year, month, day)
        return self.bday

    def ageindays(self):
        '''get age in days'''
        if self.bday is not None:
            return (datetime.date.today() - self.inputdate()).days
        return ValueError('Age isn\'t entered')

    def getproperage(self):
        '''get age in terms of year, month and day,
        not considering leap year and every month have 30 days'''
        total_days = self.ageindays()
        remain_days, years, months = 0, 0, 0
        if total_days >= 365:
            years = total_days // 365
            remain_days = total_days % 365
        if remain_days >= 30:
            months = remain_days // 30
            remain_days = remain_days % 30
        print('Age is: ', years, ' years, ', months, ' months, ',
              remain_days, ' days')


if __name__ == "__main__":
    fetching_date = input('Enter birthdate: ')
    first_person = Birthdate(fetching_date)

    first_person.getproperage()
