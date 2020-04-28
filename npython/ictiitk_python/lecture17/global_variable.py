#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-27
Description: learining for declaration of global variables
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-27
"""
PI = 3.14
PROMPT = '> '


# function to get perimeter <<<
def perimeter(radius):
    '''Inside permiter function'''
    result = 2 * PI * radius
    print("Printing result for perimeter")
    print(result)
    print(result)
    print("{:.3f}".format(result))
    print("%.3f" % (result))
    print("%.3f" % round(result, 3))
    print("{:.15f}".format(round(result, 3)))
# >>>


# function to get area <<<
def area(radius):
    '''Inside area function'''
    result = PI * radius * radius
    print("Printing result for area")
    print(result)
    print("{:.3f}".format(result))
    print("%.3f" % (result))
    print("%.3f" % round(result, 3))
    print("{:.15f}".format(round(result, 3)))
# >>>


# main function <<<
def main():
    '''Inside main function'''
    global PI
    print("Old value of PI is: ", PI)
    choice = input(PROMPT)
    if choice != 'more':
        perimeter(10)
        area(5)
    else:
        # since global keyword is used so this new value will be assigned to PI
        PI = 3.14159
        perimeter(10)
        area(5)

    print("New value of PI is ", PI)
# >>>


if __name__ == "__main__":
    main()
