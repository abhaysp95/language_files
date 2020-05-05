#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-05
Description: learing importing of class
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-05
"""

from car_class import ElectricCar


def main():
    '''Entering in main function'''
    first_ecar = ElectricCar('Tesla', 'Model S', 2017)
    print(first_ecar.get_descriptive_name())
    first_ecar.battery.describe_battery()
    first_ecar.battery.get_range()


if __name__ == "__main__":
    main()
