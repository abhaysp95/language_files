#!/usr/bin/env python3

class Node:
    def __init__(self, value = None):
        self.__data = value
        self.__next = None

    def get_data(self):
        return self.__data

    def get_next(self):
        return self.__next

    def set_data(self, value):
        self.__data = value

    def set_next(self, node):
        self.__next = node

class LinkedList:
    def __init__(self):
        self.__head = None

    def get_head(self):
        return self.__head

    def insert(self, value):
        newNode = Node(value)
        if self.__head is None:
            self.__head = newNode
        else:
            ptr = self.__head
            while ptr.get_next() is not None:
                ptr = ptr.get_next()
            ptr.set_next(newNode)

    def traverse(self):
        if self.__head is None:
            print("Nothing to traverse")
        else:
            ptr = self.__head
            while ptr is not None:
                print(ptr.get_data(), end=" ")
                ptr = ptr.get_next()
            print()

class Stack:
    def __init__(self, size=10):
        self.__max_size = size
        self.__elements = [None] * size
        self.__top = -1

    def push(self, value):
        if self.__top == self.__max_size - 1:
            print("Overflow")
        else:
            self.__top += 1
            self.__elements[self.__top] = value

    def pop(self):
        if self.__top == -1:
            print("Underflow")
            return False
        n = self.__elements[self.__top]
        self.__top -= 1
        return n

    def traverse(self):
        if self.__top == -1:
            print("Underflow")
        else:
            idx = self.__top
            while idx >= 0:
                print(self.__elements[idx], end=" ")
                idx -= 1
            print()

# function 'generate' provided by question

def generate(input_linked_list, input_stack):
    temp = input_linked_list.get_head()
    element = 0
    while (temp.get_next() is not None):
        temp.set_data(temp.get_data() + temp.get_next().get_data() + element)
        if temp.get_data() % 2 != 0:
            temp.set_data(temp.get_data() + input_stack.pop())
            element = temp.get_data()
        else:
            input_stack.push(element)
            element = temp.get_next().get_data()
        temp = temp.get_next()
    temp.set_data(temp.get_data() + input_stack.pop())

def main():
    ll = LinkedList()
    i_stack = Stack()
    ll.insert(1)
    ll.insert(2)
    ll.insert(5)
    ll.insert(3)
    print("initial linked list: ")
    ll.traverse()
    i_stack.push(10)
    i_stack.push(5)
    i_stack.push(2)
    i_stack.push(4)
    print("initial stack: ")
    i_stack.traverse()
    generate(ll, i_stack)
    print("after generate linked list: ")
    ll.traverse()
    print("after generate stack: ")
    i_stack.traverse()

main()
