#!/usr/bin/env python3

'''
example of thread locking
'''

import threading
import time

x = 16392

# def double():
    # global x
    # while x < 32784:
        # x *= 2
        # print(x)
        # time.sleep(1)
    # print("Reached Maximum")

# def half():
    # global x
    # while x > 1:
        # x //= 2
        # print(x)
        # time.sleep(1)
    # print("Reached Minimum")

# so, reaching maximum or minimum with this is very much difficult


# let's look at the locking now

lock = threading.Lock()

def double():
    global x, lock
    lock.acquire() # if this function gets the thread then it acquires and
    # locks this thread to itself
    while x < 32768:
        x *= 2
        print(x)
        time.sleep(0.5)
    print("Reached Maximum")
    lock.release()

def half():
    global x, lock
    lock.acquire()
    while x > 1:
        x //= 2
        print(x)
        time.sleep(0.5)
    print("Reached Minimum")
    lock.release()


t1 = threading.Thread(target=half)
t2 = threading.Thread(target=double)

t1.start()
t2.start()
