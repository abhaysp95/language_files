#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-10
Description: Normal Object Oriented Program
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-10
"""


def main():
    '''Entering in main function'''
    class Mobile:  # pylint: disable=too-few-public-methods
        '''Mobile Class'''
        def __init__(self, Brand, Money, Build):
            self.company = Brand
            self.price = Money
            self.model = Build

        def show(self):
            '''Function to show object values'''
            print("Name of Company: "+self.company)
            print("Price: ", self.price)
            print("Model: "+self.model)

    obj1 = Mobile('Nokia', 12000, 'A6 Plus')
    obj2 = Mobile('Samsung', 62000, 'S9')
    obj3 = Mobile('Asus', 13000, 'Max Pro M1')
    print(obj1.show(), '\n')
    print(obj2.show(), '\n')
    print(obj3.show(), '\n')

    # we can also access attribute of a class with object
    print(obj1.model, '\n')


if __name__ == "__main__":
    print(main().__doc__)
    main()
