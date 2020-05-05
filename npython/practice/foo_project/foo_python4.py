#!/usr/bin/env python


class Pets:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def show(self):
        print(f"I'm {self.name} and I'm {self.age} years old")

    def speak(self):
        print("I dunno what to say")


class Cat(Pets):
    def __init__(self, name, age, color):
        super().__init__(name, age)
        self.color = color

    def show(self):
        print(f"I'm {self.name} and I'm {self.age} years old", end=' ')
        print(f"and my colors is {self.color}")

    def speak(self):
        print("Meow")


class Dog(Pets):
    def speak(self):
        print("Bark")


class Fish(Pets):
    pass


p = Pets("Tim", 19)
print(p.show())
c = Cat("Bill", 23, "green")
print(c.show())
print(c.speak())
d = Dog('Butch', 8)
print(d.show())
print(d.speak())

f = Fish("bubble", 10)
print(f.speak())
