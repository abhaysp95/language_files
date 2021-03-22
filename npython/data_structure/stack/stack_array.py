#!/usr/bin/env python3

class Struct:
    def __init__(self, size = None):
        self.__max = size
        self.__elements = [None] * self.__max
        self.__top = -1

    def push(self, n):
        '''check overflow before inserting'''
        if self.__top == self.__max - 1:
            print("Stack Overflow")
            return False
        else:
            self.__top += 1
            self.__elements[self.__top] = n  # it's just append

    def pop(self):
        '''underflow'''
        if self.__top == -1:
            print("Stack Underflow")
            return False
        else:
            n = self.__elements[self.__top]
            self.__top -= 1
            return n

    def traverse(self):
        if self.__top == -1:
            print("Nothing to traverse")
            return
        else:
            count = 0
            while count <= self.__top:
                print(self.__elements[count])
                count += 1


s = Struct(10)
s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.push(5)
s.push(6)
s.pop()
s.pop()
s.traverse()
