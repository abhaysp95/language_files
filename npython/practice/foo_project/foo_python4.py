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
    def __init__(self, name, age, size):
        super().__init__(name, age)
        self.size = size

    def give_size(self):
        print('My size is ', self.size)


p = Pets("Tim", 19)
# print(p.show())
p.show()
p.speak()
c = Cat("Bill", 23, "green")
# print(c.show())
c.show()
# print(c.speak())
c.speak()
d = Dog('Butch', 8)
# print(d.show())
# print(d.speak())
d.show()
d.speak()

f = Fish("bubble", 10, 'big')
# print(f.speak())
f.show()
f.speak()
f.give_size()
