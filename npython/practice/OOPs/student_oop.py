#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-10
Description: basic student object oriented programming
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-10
"""


def main():
    '''Entering in main function'''
    # init constructor
    class Student:  # pylint: disable=too-few-public-methods
        '''student class'''
        def __init__(self, n, c, b, a):
            self.name = n
            self.course = c
            self.branch = b
            self.age = a

        def view(self):
            '''function to print objects'''
            print("Name: "+self.name)
            print("Course: "+self.course)
            print("Branch: "+self.branch)
            print("Age: ", self.age)

    student1 = Student('Dheeraj', 'B.A.', 'History', 24)
    student2 = Student('Praveen', 'B.Tech', 'CS', 21)
    student3 = Student('Sachin', 'B.Com', 'Commerce', 22)

    print(Student.__doc__)
    print(student1.view(), '\n')
    print(student2.view(), '\n')
    print(student3.view(), '\n')


if __name__ == "__main__":
    print(main.__doc__)
    main()
