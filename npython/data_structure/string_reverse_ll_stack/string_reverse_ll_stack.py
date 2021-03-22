#!/usr/bin/env python3

class Node:
    def __init__(self, value):
        self.__data = value
        self.__next = None

    def get_data(self):
        return self.__data

    def get_next(self):
        return self.__next

    def set_data(self, data):
        self.__data = data

    def set_next(self, node):
        self.__next = node

class Stack:
    def __init__(self):
        self.__head = None
        self.__tail = None

    def push(self, value):
        newNode = Node(value)
        if self.__head is None:
            self.__head = self.__tail = newNode
        else:
            self.__tail.set_next(newNode)
            self.__tail = newNode

    def pop(self):
        if self.__head is None:
            print("Nothing to pop")
            return ""
        else:
            n = self.__tail.get_data()
            ptr = self.__head
            if self.__head != self.__tail:
                while ptr.get_next() is not self.__tail:
                    ptr = ptr.get_next()
                ptr.set_next(None)
                self.__tail = ptr
            return n

    def traverse(self):
        ptr = self.__head
        while ptr.get_next() is not None:
            print(ptr.get_data())
        print(ptr.get_data())

def main():
    input_str = input("Enter the string: ")
    stack = Stack()
    for x in input_str:
        stack.push(x)
    output_str=""
    for x in range(len(input_str)):
        output_str += stack.pop()
    print(output_str)

main()
