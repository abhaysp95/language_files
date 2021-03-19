#!/usr/bin/env python3

class Node:
    def __init__(self, value=None):
        self.data = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # def insertBegining(self, value):
        # if self.head is None:
            # self.head = Node(value)
        # else:
            # ptr = Node(value)
            # ptr.next = self.head
            # self.head = ptr

    def insertEnd(self, value):
        if self.head is None:
            self.head = self.tail = Node(value)
        else:
            tempNode = Node(value)
            self.tail.next = tempNode
            self.tail = tempNode

    def reverse(self):
        if self.head is None:
            print("Nothing to reverse")
            return
        else:
            ptr = self.head
            pptr = self.tail  # new temporary head
            while self.head != self.tail:
                ptr = self.head
                while ptr.next != self.tail:
                    ptr = ptr.next
                self.tail.next = ptr
                self.tail = ptr
                print("new tail: ", self.tail.data)
            self.tail.next = None
            self.head = pptr


    def traverse(self):
        ptr = self.head
        if self.head is None:
            print("[EE] Nothing to traverse")
        else:
            while ptr.next is not None:
                print(ptr.data)
                ptr = ptr.next
            print(ptr.data)

def main():
    count = int(input("Enter count: "))
    inputs = [int(x) for x in input("Enter space seperated values: ").split()]
    ll = LinkedList()
    for x in inputs:
        ll.insertEnd(x)
    ll.traverse()
    # print("tail: ", ll.tail.data)
    ll.reverse()
    ll.traverse()

main()
