#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-10
Description: general max comparision with OOP
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-10
"""


# example of polymorphism
def main():
    '''Entering in main function
    Description = Example of Polymorphism'''
    class Calc:  # pylint: disable=too-few-public-methods
        '''class for comparision'''
        def max(self, a, b):
            '''comparison with two arg'''
            return a if a > b else b

        def max(self, a, b, c):
            '''comparision with three arg'''
            if a > b and a > c:
                return a
            elif b > a and b > c:
                return b
            else:
                return c

    obj1 = Calc()
    obj2 = Calc()

    print(obj1.max(20, 10))
    print(obj2.max(2, 10, 5))


if __name__ == "__main__":
    print(main.__doc__)
    main()
