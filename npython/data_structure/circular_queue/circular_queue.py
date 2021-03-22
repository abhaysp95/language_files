#!/usr/bin/env python3

class Queue:
    def __init__(self, size = None):
        self.__max = size
        self.__elements = [None] * size
        self.__front = 0
        self.__rear = -1

    def isOverflow(self):
        if (self.__rear == self.__max - 1 and self.__front == 0) or (self.__rear + 1 == self.__front and self.__front != 0):
            return True
        else:
            return False

    def isUnderflow(self):
        if (self.__front > self.__rear):
            return True
        else:
            return False

    def insert(self, value):
        if self.isOverflow():
            print("Overflow")
        else:
            if self.__rear + 1 == self.__max:
                self.__rear = -1
            self.__rear += 1
            self.__elements[self.__rear] = value
            print("rear is: ", self.__rear)

    def delete(self):
        if self.isUnderflow():
            print("Underflow")
            return True
        if self.__front == self.__max:
            self.__front = 0
        n = self.__elements[self.__front]
        self.__front += 1
        return n

    def traverse(self):
        if self.isUnderflow() and self.__elements[self.__rear] is None:
            print("Underflow")
        else:
            idx = self.__front
            count = self.__max
            # infinite loop here
            while idx != self.__rear:
                if idx == self.__max:
                    idx = 0
                print(self.__elements[idx])
                idx += 1
            print(self.__elements[idx])


def printOptions():
    print("""
Enter the choice:
1. Insert
2. Delete
3. Traverse
4. Exit""")

def main():
    q = Queue(3)
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
