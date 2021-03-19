#!/usr/bin/env python3

class A:
    def f1(self):
        print("f1 without parameter")
    def f1(self, x):
        print("f1 with parameter", x)

a = A()
# a.f1()  # method overloading is not supported, since always last one will be called, so this one will give error
a.f1(10)
