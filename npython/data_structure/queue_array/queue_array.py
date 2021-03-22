#!/usr/bin/env python3

class Queue:
    def __init__(self, size):
        self.__max = size
        self.__elements = [None] * size
        self.__front = 0
        self.__rear = -1

    def isOverflow(self):
        if self.__rear == self.__max - 1:
            return True
        else:
            return False

    def isUnderflow(self):
        if self.__front > self.__rear:
            return True
        else:
            return False

    def insert(self, value):
        if self.isOverflow():
            print("Overflow")
        else:
            self.__rear += 1
            self.__elements[self.__rear] = value

    def delete(self):
        if self.isUnderflow():
            print("Underflow")
            return False
        else:
            n = self.__elements[self.__front]
            self.__front += 1

    def traverse(self):
        if self.isUnderflow():
            print("Nothing to print")
        else:
            idx = self.__front
            while idx != self.__rear:
                print(self.__elements[idx], end=" ")
                idx += 1
            print(self.__elements[self.__rear])

def printOptions():
    print("""
Enter the choice:
1. Insert
2. Delete
3. Traverse
4. Exit""")

def main():
    q = Queue(20)
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
        elif choice == 3:
            print("Traversing: ")
            q.traverse()
        printOptions()
        choice = int(input())
    print("Exiting!!!")

main()
