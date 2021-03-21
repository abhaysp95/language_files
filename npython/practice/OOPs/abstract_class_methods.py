#!/usr/bin/env python3

'''
python provides module that provides base for defining Abstract Base Classes(ABC)
and that module name is ABC
'''

import abc
from abc import ABC, abstractmethod

class Polygon(ABC):
    @abstractmethod
    def noOfSides(self, sides):
        raise NotImplementedError

    def notAbstract(self):  # you still can't create object of Polygon, although this method is not needed to overridden necesserily
        print("Parent not abstract")

class Triangle(Polygon):
    def noOfSides(self, sides):
        print("I have ", sides, " sides")

class Quadrilateral(Polygon):
    def noOfSides(self):  # unlike Java,C++(maybe) this dosn't checks method signature
        print("I have 4 sides")

class Pentagon(Polygon):
    def noOfSides(self):
        print("I have 5 sides")

class Hexagon(Polygon):
    def noOfSides(self):
        print("I have 6 sides")

    def notAbstract(self):
        super().notAbstract()  # else, object of Hexagon will call this method not the parent class's(as expected)
        print("Hexagon not abstract")

t = Triangle()
t.noOfSides(3)

q = Quadrilateral()
q.noOfSides()

p = Pentagon()  # can't instantiate abstract class Pentagon with abstract method noOfSides
# so if you don't override abstract method the child class also becomes abstract class
# p.sides()
p.noOfSides()

h = Hexagon()
h.notAbstract()


# testing abstractproperty

class Parent(ABC):
    @abc.abstractproperty
    def aMethod(self):
        return "this is parent class"

class Child(Parent):
    @property
    def aMethod(self):
        return "this is child class"

try:
    p = Parent()
    print(p.aMethod)
except Exception as err:
    print(err)

c = Child()
print(c.aMethod)  # for c.aMethod() gives str method is not callable
