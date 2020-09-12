#!/usr/bin/env python3

import threading

def function1():
    for _ in range(10000):
        print("ONE")

def function2():
    for _ in range(10000):
        print("TWO")

t1 = threading.Thread(target=function1)
t2 = threading.Thread(target=function2)

t1.start()
# t1.join()  # this means that main thread will wait for the one thread t1 to finish
t2.start()
