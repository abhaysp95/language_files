#!/usr/bin/env python3

from classes_objects import Person

# inheritance
class Worker(Person):

    def __init__(self, name, age, height, salary):
        super(Worker, self).__init__(name, age, height)
        self.salary = salary

    def __str__(self):
        text = super(Worker, self).__str__()
        text += " and also Worker class"
        return text

    def yearly_salary(self):
        return self.salary * 12

# operator overriding
class Vector:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def __str__(self):
        return "x: {}, y: {}".format(self.x, self.y)


def main():
    worker1 = Worker('Jimmy', 43, 5.09, 1000)
    print(worker1.yearly_salary())
    print(worker1)

    v1 = Vector(3, 4)
    v2 = Vector(4, 5)

    print(v1)
    print(v2)

    v3 = v1 + v2
    v4 = v1 - v2

    print(v3)
    print(v4)


if __name__ == "__main__":
    main()
