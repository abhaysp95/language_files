#!/usr/bin/env python3

class A:
    def f1(self):
        print("Class A")

class B(A):
    def f2(self):
        print("Class B")

ob = B()
ob.f1()
ob.f2()
