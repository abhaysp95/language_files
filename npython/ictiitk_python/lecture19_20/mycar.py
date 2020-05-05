#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-05
Description: importing class
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-05
"""

from car_class import Car


def main():
    '''Entering in main function'''
    mynewcar = Car('Mahindra', 'Thar', 2019)
    print(mynewcar.get_descriptive_name())
    mynewcar.odometer_reading = 32
    mynewcar.read_odometer()


if __name__ == "__main__":
    main()
