#!/usr/bin/env python3

'''
example of thread locking
'''

import threading
import time

x = 16392

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
