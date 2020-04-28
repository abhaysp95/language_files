#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-28
Description: making restaurant class, learning basic OOP
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-28
"""


# restaurant class <<<
class Restaurant:
    '''Specifying restaurant class'''
    def __init__(self, restaurant_name, cuisine_type):
        self.name = restaurant_name
        self.type = cuisine_type

    def describe_restaurant(self):
        '''Giving information about restaurant'''
        print(f"Name of the restaurant is {(self.name).title()}.")
        print(f"This is of {(self.type).title()} type.")

    def open_restaurant(self):
        '''Giving the current status of restaurant'''
        print(f"Restaurant {(self.name).title()} is currently open")
# >>>


# main function <<<
def main():
    '''Entering in main class'''
    first_restaurant = Restaurant("kanha Shyam", "Indian")
    second_restaurant = Restaurant("leaky cauldran", "English")

    print(f"Name of first_restaurant is {(first_restaurant.name).title()}")
    print(f"This restaurant is of {(first_restaurant.type).title()} type.")

    first_restaurant.describe_restaurant()
    first_restaurant.open_restaurant()

    print(f"Name of second_restaurant is {(second_restaurant.name).title()}")
    print(f"This restaurant is of {(second_restaurant.type).title()} type.")

    second_restaurant.describe_restaurant()
    second_restaurant.open_restaurant()
# >>>


if __name__ == "__main__":
    main()
