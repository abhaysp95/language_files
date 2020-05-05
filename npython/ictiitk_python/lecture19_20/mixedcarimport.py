#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-05
Description: learning multiple class import
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-05
"""

from car_class import Car, ElectricCar


def main():
    '''Inside main function'''
    my_dzire = Car('suzuki', 'dzire', 2018)
    my_hyundai = Car('hyundai', 'Creta', 2019)

    print(my_dzire.get_descriptive_name())
    print(my_hyundai.get_descriptive_name())


if __name__ == "__main__":
    main()
