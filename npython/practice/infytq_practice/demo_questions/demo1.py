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
                print(ptr.get_data())
                ptr = ptr.get_next()


# all the above code is backup code to execute the following function

# function provided in question
def calculate_total(head):
    total = 0
    if (head == None):
        return
    temp = head
    while (temp != None and temp.get_next() != None):
        if temp.get_data() <= temp.get_next().get_data():
            total += temp.get_next().get_data()
        else:
            total += temp.get_data()
        temp = temp.get_next()
    temp.set_data(total)  # temp will be last here

def main():
    ll = LinkedList()
    # linked list data provided in question
    ll.insert(2)
    ll.insert(8)
    ll.insert(3)
    ll.insert(5)
    ll.insert(11)
    print("initial ll: ")
    ll.traverse()
    calculate_total(ll.get_head())  # asked, output after executing this function
    print("after calculate_total, ll: ")
    ll.traverse()

main()
