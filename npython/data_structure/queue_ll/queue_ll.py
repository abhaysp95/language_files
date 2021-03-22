#!/usr/bin/env python3

class Node:
    def __init__(self, value=None):
        self.data = value
        self.next = None

class Queue:
    def __init__(self):
        self.__front = self.__rear = None

    # no overflow in case of linked list

    def isUnderflow(self):
        if self.__front is None:
            return True
        else:
            return False

    def insert(self, value):
        newNode = Node(value)
        if self.__front is None:
            self.__front = self.__rear = newNode
        else:
            self.__rear.next = newNode
            self.__rear = newNode

    def delete(self):
        if self.isUnderflow():
            return False
        else:
            n = self.__front.data
            if self.__front is not self.__rear:
                ptr = self.__front
                self.__front = self.__front.next
            return n

    def traverse(self):
        if self.isUnderflow():
            return False
        ptr = self.__front
        while ptr is not self.__rear:
            print(ptr.data, end=" ")
            ptr = ptr.next
        print(ptr.data)


def printOptions():
    print("""
Enter the choice:
1. Insert
2. Delete
3. Traverse
4. Exit""")

def main():
    q = Queue()
    printOptions()
    choice = int(input())
    while choice != 4:
        print("choice is: ", choice)
        if choice == 1:
            value = input("Enter the value to insert: ")
            q.insert(value)
        elif choice == 2:
            n = q.delete()
            print("deleted: ", n)
            pass
        elif choice == 3:
            print("Traversing: ")
            q.traverse()
        printOptions()
        choice = int(input())
    print("Exiting!!!")

main()
