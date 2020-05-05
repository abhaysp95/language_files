#!/usr/bin/env python


class Person:
    number_of_people = 0

    def __init__(self, name):
        self.name = name
        Person.number_of_people += 1

    @classmethod
    def number_of_people_(cls):
        return cls.number_of_people

    @classmethod
    def add_person(cls):
        cls.number_of_people += 1

p1 = Person('Tim')
print(Person.number_of_people)
p2 = Person('Bill')
print(Person.number_of_people)

print(Person.number_of_people_())
