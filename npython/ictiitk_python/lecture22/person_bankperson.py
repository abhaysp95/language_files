#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
A person class which contains information about them
"""

import datetime
import get_age


class Person(object):
    '''creating a person'''
    # the object is not required as argument in in class name as shown above
    # in python3
    # It is used to convert classic style class to new style class but
    # in python3 all classes are new style class

    def __init__(self, name):
        self.name = name
        try:
            lastblank = name.rindex(' ')
            self.lastname = name[lastblank + 1:]
        except:
            self.lastname = name
        self.birthdate = None

    def getname(self):
        '''get name'''
        return self.name

    def getlastname(self):
        '''get last name'''
        return self.lastname

    def setbirthdate(self, birthdate):
        '''set birthdate'''
        self.birthdate = birthdate

    def getage(self):
        '''get age of person'''
        return get_age.Birthdate(self.birthdate).getproperage()

    def __lt__(self, other):
        '''compare two names'''
        if self.lastname == other.lastname:
            return self.name < other.name
        return self.lastname < other.lastname

    def __str__(self):
        '''returns formatted name'''
        return self.name


def main():
    '''Inside main function'''
    myself = Person('Abhay Shanker Pathak')
    cat = Person('garfield')
    bat = Person('Bruce Wayne')

    bat.setbirthdate(datetime.date(1939, 5, 27))
    cat.setbirthdate(datetime.date(1978, 6, 19))
    print(bat.birthdate)

    print(bat.getage())
    print(myself.getlastname())
    print(cat.getlastname())

    print(Person.__str__(myself))

    print(Person.__lt__(myself, bat))

    str(myself)
    str(cat)
    str(bat)

    def testperson():
        '''test function'''
        plist = [myself, cat, bat]
        for per in plist:
            print(per)
        print('==sorted==')
        plist.sort()
        for per in plist:
            print(per)

    testperson()


if __name__ == "__main__":
    main()
