#!/usr/bin/env python3

class Person:

    amount = 0

    # constructor
    def __init__(self, name, age, height):
        self.name = name
        self.age = age
        self.height = height
        Person.amount += 1

    def print(self):
        print(self.name)
        print(self.age)
        print(self.height)

    # for print(Person object)
    def __str__(self):
        return "This is Person class"
    # so we can actually use this instead of print(self) method

    # destructor
    def __del__(self):
        print("Object Deleted")
        Person.amount -= 1


def main():
    person1 = Person('joey', '31', 5.10)
    person2 = Person('chandler', '32', 5.11)
    person3 = Person('ross', '32', 6)
    person1.print()
    person2.print()
    person3.print()
    print(person1)
    print(person2)
    print(person3)
    print(Person.amount)
    print("Deleting person2")
    del person2
    print(Person.amount)
    print("Deleting person3 and person1")
    del person3
    del person1
    print(Person.amount)


if __name__ == "__main__":
    main()
