#!/usr/bin/env python3

from abc import ABC, ABCMeta, abstractmethod

class Test:
    def one(self):
        return self.two()  # you can call stuff from after

    def two(self):
        return 'A'

    def three(self):
        try:
            num = 5 / 1
            print('try')
            assert(5 == 5)  # if not True, then AssertionError
        except ZeroDivisionError:
            print('except')
        else:
            print('this')  # else only works one try is successful

t = Test()
print(t.two())
print(t.one())
t.three()

class TestABS(metaclass=ABCMeta):
    counter = 0

    @abstractmethod
    def print_this(self):
        print("This is good")

    @staticmethod
    def print_couter():
        print("counter is: ", TestABS.counter)

# TestABS().print_couter()  # is not possible because, object can't be created of the abstract class

class TestChildABS(TestABS):
    def __init__(self):
        TestABS.counter += 1

    def print_this(self):
        print("This is good absolutely")

tc = TestChildABS()
tc.print_this()
# tc.print_couter() # 1
TestChildABS().print_couter() # 2
tc2 = TestChildABS()
tc2.print_couter() # 3
