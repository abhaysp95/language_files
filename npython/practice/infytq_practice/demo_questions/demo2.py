#!/usr/bin/env python3

class Queue:
    def __init__(self, size = 10):
        self.__max_size = size
        self.__front = 0
        self.__rear = -1
        self.__elements = [None] * size

    def is_empty(self):
        # condition for underflow:
        if self.__front > self.__rear:
            print("Underflow")
            return True
        return False

    def enque(self, value):
        # check overflow
        if self.__rear == self.__max_size - 1:
            print("Overflow")
        else:
            self.__rear += 1
            self.__elements[self.__rear] = value

    def deque(self):
        # check underflow
        if self.is_empty():
            return False
        else:
            n = self.__elements[self.__front]
            self.__front += 1
            return n

    def traverse(self):
        # check underflow
        if self.is_empty():
            print("Underflow")
        else:
            idx = self.__front
            while idx <= self.__rear:
                print(self.__elements[idx])
                idx += 1

# function provided in question
def function(input_queue):
    output_queue = Queue(10)
    while (not input_queue.is_empty()):
        var = input_queue.deque()
        if var <= 5:
            output_queue.enque(input_queue.deque() + 1)
        else:
            output_queue.enque(output_queue.deque() + input_queue.deque())
    return output_queue

def main():
    iq = Queue(10)
    iq.enque(3)
    iq.enque(7)
    iq.enque(6)
    iq.enque(2)
    iq.enque(5)
    iq.enque(6)
    iq.enque(3)
    iq.enque(2)
    print("initial iq: ")
    iq.traverse()
    oq = function(iq)
    print("got oq: ")
    oq.traverse()

main()
