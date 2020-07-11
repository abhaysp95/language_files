#!/usr/bin/env python3

import sys

randomlist = ['a', 0, '-', -1, 3]

def first_example():
    for entry in randomlist:
        try:
            print("The entry is ", entry)
            r = 1/int(entry)
            break
        except:
            # use sys.exc_info() to get name of the exception
            # print(sys.exc_info())
            print("Ooops! ", sys.exc_info()[0], " occured.")
            print("Next Entry")
            print()
    print("The reciprocal of ", entry, " is ", r)


# since every exception in Python inherits from the Exception class,
# the above task can be performed in following way
def second_example():
    for entry in randomlist:
        try:
            print("The entry is ", entry)
            r = 1/int(entry)
            break
        except Exception as e:
            print("Oops!", e.__class__, "occured")
            print("Next Entry.")
            print()
    print("The reciprocal of ", entry, " is ", r)


# catch specific exceptions in python
def third_example():
    for entry in randomlist:
        # a try clause can have multiple except clause
        # however, only one will be executed in case of an execption occurs
        try:
            print("The entry is ", entry)
            r = 1 / int(entry)
            break
        except ValueError:
            print('ValueError happened')
            print("Next Entry.")
            print()
        except (TypeError, ZeroDivisionError):
            print('Either TypeError or ZeroDivisionError')
            print('This is ', sys.exc_info()[0])
            print("Next Entry")
            print()
        except:
            print('Some other error, then defined')
            print('This is ', sys.exc_info()[0])
            print("Next Entry")
            print()
    print('The reciprocal of ', entry, ' is ', r)


# second_example()
third_example()
