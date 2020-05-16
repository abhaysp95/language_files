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
        get_age.Birthdate(self.birthdate).getproperage()

    def __lt__(self, other):
        '''compare two names'''
        if self.lastname == other.lastname:
            return self.name < other.name
        return self.lastname < other.lastname

    def __str__(self):
        '''returns formatted name'''
        return self.name


class BankPerson(Person):
    '''class for bank person'''
    nextId = 0

    def __init__(self, name):
        Person.__init__(self, name)
        self.idnum = BankPerson.nextId
        BankPerson.nextId += 1

    def getid(self):
        '''returns id'''
        return self.idnum

    def __lt__(self, other):
        '''compares two bank persons'''
        return self.idnum < other.idnum

    def isCustomer(self):
        return isinstance(self, Customer)


class Customer(BankPerson):
    '''Customer class inheriting bank person class'''

    def __init__(self, name):
        BankPerson.__init__(self, name)
        self.savings = []
        self.FDs = []

    def addSavingsAcc(self, acc_num):
        self.savings.append(acc_num)

    def addFD(self, fd):
        self.FDs.append(fd)

    def removeFD(self, fd):
        self.FDs.remove(fd)

    # this here is private function, starts with _, can't be accessed directly
    # although, this is just a naming convention
    # this function can be accessed directly but it shouldn't be
    def _clone_sort(self, acc_num):
        clone = acc_num[:]
        clone.sort()
        return clone

    def return_savings(self):
        return self._clone_sort(self.savings)

    def return_FDs(self):
        return self._clone_sort(self.FDs)


class NormalCustomer(Customer):
    '''creating a blank class to  be safe,
    in case some conditions appears in future'''
    pass


class PremiumCustomer(Customer):
    '''based on with the dedicated relation bank manager'''

    def __init__(self, name, relmanager):
        Customer.__init__(self, name)
        self.relmanager = relmanager

    def getrelmanager(self):
        return self.relmanager


class Employee(BankPerson):
    '''currently leaving blank'''
    pass


def main():
    '''Inside main function'''
    myself = Person('Abhay Shanker Pathak')
    cat = Person('garfield')
    bat = Person('Bruce Wayne')

    print(myself.__dict__)
    bat.setbirthdate(datetime.date(1939, 5, 27))
    cat.setbirthdate(datetime.date(1978, 6, 19))
    print(bat.birthdate)
    bat.getage()
    print(myself.getlastname())
    print(cat.getlastname())
    print(Person.__str__(myself))
    print(Person.__lt__(myself, bat))
    str(myself)  # this is same as __str__
    str(cat)
    str(bat)
    print(myself < bat)  # this is same as __lt__

    print('testperson function declared here')

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

    print('testbankperson declared here')

    def testbankperson():
        '''function to test methods of class BankPerson'''
        per1 = Person('Om Namah Shivaay')
        per2 = BankPerson('Victor Stone')
        per3 = BankPerson('Om Namah Shivaay')
        per4 = BankPerson('Stan Browny')
        print('P2 is ', per2)
        print('2 id is ', per2.getid())
        print('3 id is ', per3.getid())
        # python will call __lt__ of Person class, as per1 is of Person class
        print('is per1 greater than per3? ', per1 < per3)
        # python will call __lt__ of BankPerson here, as first object is per3
        # print('is per3 greater than per1? ', per3 < per1)
        print('is per3 greater than per4? ', per3 < per4)
        print('is per1 greater than per4? ', per1 < per4)
        print('is per1 greater than per4? ', per1 < per4)

    testbankperson()

    print('testcustomer from here')

    def testcustomer():
        '''function to test customer class'''
        per1 = Person('Abhay Shanker Pathak')
        per2 = Customer('Victor Stone')
        per3 = Customer('Abhay Shanker Pathak')
        per4 = Customer('Stan Browny')

        print('Id of p3 is ', per3.getid())
        print('Id of p4 is ', per4.getid())
        print('person2 < person3', per2 < per3)
        print('person4 < person3', per4 < per3)
        print('person1 < person3', per1 < per3)

        per2.addSavingsAcc(23)
        per3.addSavingsAcc(3589)
        per4.addSavingsAcc(3921)
        per2.addSavingsAcc(48932)
        per2.addSavingsAcc(52932)

        per3.addFD(392)
        per4.addFD(3400)
        per2.addFD(309)
        per4.addFD(5932)

        print('type of person1 is: ', type(per1))
        print('type of person2 is: ', type(per2))
        print('isinstance of per1 is Person: ', isinstance(per1, Person))
        print('isinstance of per2 is Customer: ', isinstance(per2, Customer))

        person_list = [per1, per2, per3, per4]
        for person in person_list:
            # if type(person) == Customer:  also works but not recommended
            if isinstance(person, Customer) is True:
                print('-----------------------------------------')
                print('For customer ', person)
                print('\tSavings account :', person.return_savings())
                print('\tFixed Deposits :', person.return_FDs())
    testcustomer()


if __name__ == "__main__":
    main()
