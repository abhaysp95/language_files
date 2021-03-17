#!/usr/bin/env python3

class Node:
    def __init__(self, value=None):
        self.data = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insertBegining(self, value):
        if self.head is None:
            self.head = Node(value)
        else:
            ptr = Node(value)
            ptr.next = self.head
            self.head = ptr

    def insertEnd(self, value):
        if self.head is None:
            self.head = Node(value)
        else:
            ptr = self.head
            while ptr.next is not None:
                ptr = ptr.next
            ptr.next = Node(value)

    def insertBefore(self, val_before, val):
        if self.head is None:
            print("[WW] No node present, this will be first")
            self.head = Node(val)
        else:
            ptr = self.head
            pptr = ptr
            value_entered = False
            while ptr.next != None:
                pptr = ptr
                if ptr.data == val_before:
                    value_entered = True
                    pptr.next = Node(val)
                    break
                pptr = pptr.next
                pptr.next = ptr
            if not value_entered:
                print("[EE] No node present with the provided value")

    def insertAfter(self, val_after, val):
        if self.head is None:
            print("[WW] No node present, this will be first")
            self.head = Node(val)
        else:
            ptr = self.head
            pptr = ptr
            value_entered = False
            while ptr.next != None:
                # work here
                if ptr.data == val_after:
                    value_entered = True
                    ptr.next = Node(val)
                    break
                ptr = ptr.next
            if not value_entered:
                print("[EE] No node present with the provided value")

    def deleteBegining(self):
        if self.head is None:
            print("[EE] Nothing to delete")
        else:
            ptr = self.head
            self.head = ptr.next

    def deleteEnd(self):
        ptr = self.head
        pptr = ptr
        while ptr.next is not None:
            pptr = ptr
            ptr = ptr.next
        pptr.next = None

    def deleteBefore(self, val_before):
        if self.head is None:
            print("[EE] Nothing to delete from here")
        elif self.head.data == val_before:
            print("[WW] This is the only node, deleting nothing")
        else:
            ptr = self.head
            pptr = ptr
            value_found = False
            while ptr.next != None:
                if ptr.data == val_before:
                    value_found = True


    def traverse(self):
        ptr = self.head
        if self.head is None:
            print("[EE] Nothing to traverse")
        else:
            while ptr.next is not None:
                print(ptr.data)
                ptr = ptr.next
            print(ptr.data)


def insertNode(pos, ll):
    value = int(input("Enter the value: "))
    if pos == "Beg":
        ll.insertBegining(value)
    elif pos == "End":
        ll.insertEnd(value)
    else:
        print("[EE] Enter correct position")
    return ll

    # insert at beg and end is left

def deleteNode(pos, ll):
    if pos == "Beg":
        ll.deleteBegining()
    elif pos == "End":
        ll.deleteEnd()
    else:
        print("[EE] Enter correct position")
    return ll

def print_options():
    print('''
Enter choices(number):
1. Insert node at begining
2. Insert node at end
3. Delete node from begining
4. Delete node from end
5. Traverse
6. Exit
            ''')

def main():
    ll = LinkedList()
    print_options()
    choice = int(input("Enter the choice: "))
    while choice != 6:
        if choice == 1:
            ll = insertNode("Beg", ll)
        elif choice == 2:
            ll = insertNode("End", ll)
        elif choice == 3:
            ll = deleteNode("Beg", ll)
        elif choice == 4:
            ll = deleteNode("End", ll)
        elif choice == 5:
            ll.traverse()
        else:
            print("[EE] provide correct option")
        print_options()
        choice = int(input("Enter the choice: "))

if __name__ == "__main__":
    main()
