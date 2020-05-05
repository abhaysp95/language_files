#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-28
Description: creating a dog class, basics of OOP
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-28
"""


# class function <<<
class Dog:
    '''A simple attempt to model a dog'''
    # capitalized names refers to class in python. No parameter given
    # because we are creating class from scratch

    def __init__(self, name_given, age_given):
        '''initialize name and age attributes'''
        self.name = name_given
        self.age = age_given

        # a function that is part of class is called method. Everything learnt
        # about function applies to method as well

        # this __init__ method will be ran automatically whenever we'll
        # create new instance based on the object class.

        # the self parameter is required in the method definition, and
        # it must come first before other parameter

        # every method call associated with an instance automatically
        # passes self, which is a reference to instance itself

        # it gives the individual instance access to the attributes and
        # methods of class

        # name and age are attributes of Dog class
        # variables that are accessible through the instance like this
        # are called attributes

    def sit(self):
        '''Simulate a dog sitting in response to command'''
        print(f"{self.name} is now sitting")

    def roll_over(self):
        '''Simulate rolling over in response to a command'''
        print(f"{self.name} rolled over!")

        # sit and roll_over are different method of Dog class
# >>>


# main class <<<
def main():
    '''Entering in main funciton'''
    # this here we created an instance of class Dog
    my_dog = Dog('bucky', 4)
    # creating another instance
    your_dog = Dog('jhonny', 5)
# after seeing the above line python calls __init__ method in Dog
# with the given arguments

# __init__ method creates an instance representing this particular dog and
# sets the name and age attributes using the value we provided.

# python then returns an instance representing this dog which is assigned
# to variable 'my_dog'

# so, basically my_dog is an instance here, and my_dog have two attributes
# name and age
    print(f"My dog's name is {(my_dog.name).title()}.")
    print(f"My dog's age is {my_dog.age}.")

    # calling methods now
    my_dog.sit()
    my_dog.roll_over()

    print()

    print(f"Your dog's name is {(your_dog.name).title()}.")
    print(f"Your dog's age is {your_dog.age}.")

    # calling methods now
    your_dog.sit()
    your_dog.roll_over()
# >>>


if __name__ == "__main__":
    main()
