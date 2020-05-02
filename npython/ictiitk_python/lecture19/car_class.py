#!/usr/bin/env python


"""
Author: Abhay Shanker Pathak
Date: 2020-04-29
Description: making car class(modifying attributes of instances)
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-29
"""

# this file also contains example of inheritance which is of lecture 20


# car class <<<
class Car:  # pylint: disable=too-few-public-methods
    '''A simple attempt to represent a car'''

    # init method <<<
    def __init__(self, company, model, year):
        '''Intialize attributes to describe a car'''
        self.make = company
        self.build = model
        self.year = year
        self.odometer_reading = 0
        self.diesel_amount = 0
    # >>>

    # description value <<<
    def get_descriptive_name(self):
        '''Returns a neatly formatted discriptinve name'''
        long_name = f"{self.year} {self.make} {self.build}"
        return long_name.title()
    # >>>

    # odometer reading <<<
    def read_odometer(self):
        '''Print a statement showing car's traveling'''
        print(f"This car has {self.odometer_reading} kilometers on it.")
    # >>>

    # update ododmeter <<<
    def update_odometer(self, mileage):
        '''Sets the odometer to the given value'''
        if mileage >= self.odometer_reading:
            self.odometer_reading = mileage
        else:
            print("You can't roll back odometer")
    # >>>

    # increment odometer <<<
    def increment_odomter(self, miles):
        '''Adding the given amount to odometer'''
        self.odometer_reading += miles
    # >>>

    # fill diesel tank of car <<<
    def diesel_tank(self, litres):
        '''Fill up the diesel tank'''
        if litres >= self.diesel_amount:
            self.diesel_amount = litres
            print("Current amount of diesel in tank is: ", self.diesel_amount,
                  " litres")
        else:
            print("Do you wanna empty the fuel the tank!")
    # >>>
# >>>


# electric car class <<<
class ElectricCar(Car):
    '''Represent ascpects of a electric car'''

    def __init__(self, company_name, model, year):
        '''initializing attributes of parent class'''
        super().__init__(company_name, model, year)
        self.battery_size = 75

    def describe_battery(self):
        '''Print a statement describing the battery size'''
        print("The has a {}-KWh battery and company is {}"
              .format(self.battery_size, self.make))

    def diesel_tank(self, litres):
        '''Do electirc cars use diesel as fuel'''
        print('This is an electric Car. It doesn\'t uses diesel as fuel')
# >>>


# main function <<<
def main():
    '''Entering in main function'''
    first_car = Car('toyota', 'innova', '2020')
    second_car = Car('toyota', 'fortuner', '2019')
    third_car = ElectricCar('hyundai', 'i8', '2018')
    print(first_car.get_descriptive_name())

    # modifying attributes value directly
    # first_car.odometer_reading = 23

    # modifying attributes with method
    first_car.update_odometer(32)

    first_car.read_odometer()

    first_car.diesel_tank(15)

    print(second_car.get_descriptive_name())
    second_car.update_odometer(23_500)
    second_car.increment_odomter(200)
    second_car.read_odometer()
    second_car.diesel_tank(27)

    print(third_car.get_descriptive_name())
    print(third_car.describe_battery())
    print(third_car.diesel_tank(20))
# >>>


if __name__ == "__main__":
    main()
