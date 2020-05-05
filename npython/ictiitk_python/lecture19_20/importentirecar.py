#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-05
Description: import entire car class
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-05
"""

import car_class


def main():
    '''Inside main function'''
    norm_car = car_class.Car('Mahindra', 'Classic', 2017)
    ecar = car_class.ElectricCar('Tesla', 'Model t', 2019)

    print(norm_car.get_descriptive_name())
    print(ecar.get_descriptive_name())


if __name__ == "__main__":
    main()
