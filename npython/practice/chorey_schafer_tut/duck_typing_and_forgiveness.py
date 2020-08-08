#!/usr/bin/env python3

'''duck typing and easier to ask for forgiveness than permission(EAFP)'''


# In duck typing we don't care if object is it's duck or not
# we care if that object can behave like duck if asked to do so

import os

class Duck:

    def quack(self):
        print('Quack, quakc')

    def fly(self):
        print('Flap, flap')


class Person:

    def quack(self):
        print("I'm quacking like a Duck")

    def fly(self):
        print("I'm flying like a Duck")


# def quack_and_fly(thing):
    # if isinstance(thing, Duck):
        # thing.quack()
        # thing.fly()
    # else:
        # print("\nThis has to be a Duck")
# this above function is not the example of duck typing, cause it's care which
# if where object belongs, not behaviour. So, it should be written as

# def quack_and_fly(thing):
    # thing.quack()
    # thing.fly()
    # print()

# now this is somewhat dangerous, so lets look at the concept of EAFP
# non-pythonic way -> Look before you leap(LBYL)
# def quack_and_fly(thing):
    # if hasattr(thing, 'quack'):
        # if callable(thing.quack):
            # thing.quack()

    # if hasattr(thing, 'fly'):
        # if callable(thing.fly):
            # thing.fly()
# now this above method, frowns upon EAFP, cause it's asking permissions everytime

# EAFP way
def quack_and_fly(thing):
    try:
        thing.quack()
        thing.fly()
        thing.bark()  # threw the attribute error
    except AttributeError as e:
        print(e)
    print()
# this concept isn't just limited to class and things, you could use it in general too


d = Duck()
quack_and_fly(d)

p = Person()
quack_and_fly(p)

print(callable(Duck))


print("\nAnother Example\n")


# person = {'name': 'Jess', 'age': 32, 'job': 'Coder'}
person = {'name': 'Jess', 'age': 32}

# LBYL
# if 'name' in person and 'age' in person and 'job' in person:
    # print("I'm {name}. I'm {age} years old and I am a {job}.".format(**person))
# else:
    # print("Missing some key")

#EAFP (pythonic)
try:
    print("I'm {name}. I'm {age} years old and I am a {job}.".format(**person))
except KeyError as e:
    print("Missing {} key".format(e))


print("\nRace Condition, why EAFP is preferred\n")

my_file = "/tmp/test.txt"

# LBYL
# if os.access(my_file, os.R_OK):
    # the problem is maybe, in the above line we were
    # able ot access file, but till reaching line below
    # we aren't able to do so
    # with open(my_file) as f:
        # print(f.read())
# else:
    # print("File can't be accessed")

# EAFP
try:
    f = open(my_file)
except IOError as e:
    print("File can't be accessed")
else:
    with f:
        print(f.read())
