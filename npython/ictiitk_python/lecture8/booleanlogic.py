#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-19
Description: Understanding boolean logic
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-19
"""

# first logic syntax <<<
cars = ['dodge', 'subaru', 'camaro', 'mustang', 'playmoth']

for car in cars:
    print("Is car == 'playmoth' ? I predict false")
    print(car == 'playmoth')
    if car == 'playmoth':
        print(f"Yes, I said it right, its {car.title()}")
    else:
        print("I got it wrong it is ", car.title())
# >>>

# second logic syntax <<<
# testing using the lower() method
for car in cars:
    print("Value is ", car.upper() == 'playmoth')

# result: as we can see if we will use upper() or title() with the string then
# it'll return false, as they are in lower case
# >>>

# third logic syntax <<<
# using numerical boolean testing
lst1 = [ "5", "10", "15", "20", "25", "30", "35", "40" ]
lst2 = [ "4", "8", "12", "16", "20", "24", "28", "32", "36", "40" ]

for i in lst2:
    print("Is num2 == num1 ? I predict yes")
    if i in lst1:
        print(i in lst1)
    else:
        print(i in lst1)
# >>>

# fourth logic syntax <<<
num = 10
lst = [ "3", "4", "12", "5", "6", "28", "45", "19", "10", "2" ]

for i in lst:
    print(i, " greater than ", num, ": ", int(i) > num)
    print(i, " less than ", num, ": ", int(i) < num)
    print(i, " greater than equal to ", num, ": ", int(i) >= num)
    print(i, " less than equal to ", num, ": ", int(i) <= num)
    print(i, " is equal to ", num, ": ", int(i) == num)
    print(i, " is not equal to ", num, ": ", int(i) != num)
    print()
# >>>

# fifth logic syntax <<<
# using `and` and `or` for boolean logic
lst3 = [ "name", "10", "date", "15", "year", "6.5" ]
lst4 = [ "10", "time", "year", "3.4" ]
lst5 = [ "name", "fame", "6.5" ]

for i in lst4:
    if i in lst4 and i in lst5:
        print("Yes")
    elif i in lst4 or i in lst5:
        print("Not so sure")
    else:
        print("No")
# >>>

# ques: couldn't understood what's the use for print(f"{name.some()}, nothing")
