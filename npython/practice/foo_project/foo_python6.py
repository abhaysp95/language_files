#!/usr/bin/env python


class Person:
    number_of_people = 0

    def __init__(self, name):
        self.name = name
        Person.number_of_people += 1

    @classmethod  # known as decorator
    def number_of_people_(cls):
        # cls.number_of_people += 1
        return cls.number_of_people

    @classmethod
    def add_person(cls):
        cls.number_of_people += 1

    @staticmethod
    def bark(num):
        '''dog barks'''
        # you can't access cls or self in staticmethod, this is just like normal
        # function, except you organized it inside class
        for _ in range(num):
            print('Wooof', end=' ')
        print()
    # you can create a class and put some staticmethod inside it and it'll be
    # good as import module


class Math:
    @staticmethod
    def add(num1, num2):
        return num1 + num2


p1 = Person('Tim')
print(Person.number_of_people)
p2 = Person('Bill')
print(Person.number_of_people)
Person.add_person()
print(Person.number_of_people)

Person.number_of_people += 1
print(Person.number_of_people_())
Person.bark(5)

print(Math.add(5, 4))
