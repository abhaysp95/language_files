#!/usr/bin/env python3

'''
A program to show method overloading
'''


class Car():
    '''A general car for class'''

    def __init__(self):
        print("You created a Car instance")

    def start(self):
        print('Car started...')

    def stop(self):
        print('Car Stopped')


class BMW(Car):
    '''A car specific to BMW'''

    def __init__(self):
        super().__init__()  # or use Car instead of super()
        print("You created a BMW car instance")

    def start(self):
        # if not so specific, just use super().start()
        super(BMW, self).start()
        # if you give self to start or __init__ as in previous
        # function, TypeError is, requires 1 provided 2
        print("You are riding BMW, enjoy ;)")

    def headsup_display(self):  # you can also make this method as function
        print("This is a new feature")


def main():
    '''main function'''
    b = BMW()
    b.start()
    b.headsup_display()
    b.stop()


if __name__ == "__main__":
    main()
