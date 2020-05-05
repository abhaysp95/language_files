#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-05
Description: creating new restaurant
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-05
"""

from restaurant_class import Restaurant


def main():
    '''Inside main function'''
    new_restaurant = Restaurant('Mama dhaba', 'Dinner')
    new_restaurant.describe_restaurant()
    new_restaurant.open_restaurant()
    new_restaurant.set_number_served(2)
    new_restaurant.set_number_served(5)
    print(new_restaurant.get_number_served())
    new_restaurant.increment_number_served(10)
    print(new_restaurant.get_number_served())


if __name__ == "__main__":
    main()
