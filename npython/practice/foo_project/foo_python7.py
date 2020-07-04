#!/usr/bin/env python


class Math:

    @staticmethod
    def add5(x):
        return x + 5

    @staticmethod
    def multiply4(x):
        return x * 4

    @staticmethod
    def pr():
        print('Program running')


Math.pr()
num = Math.add5(23)
print(Math.multiply4(num))
