#!/usr/bin/env python3

class A:
    def __init__(self, x):
        self.x = x

    def print_x(self):
        print("A x is: ", self.x)

class B(A):
    def __init__(self, x, y):
        super().__init__(x)
        self.y = y

    def print_y(self):
        print("B y is: ", self.y)

ob = B(10, 20)
ob.print_y()
