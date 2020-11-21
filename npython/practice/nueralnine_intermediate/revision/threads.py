#!/usr/bin/env python3

import threading
import time

text = ""

def readfile():
    global text
    while True:
        with open('test.txt', 'r') as rfile:
            text = rfile.read()
        time.sleep(3)

def printloop():
    for x in range(30):
        print(text)
        time.sleep(1)

t1 = threading.Thread(target=readfile, daemon=True)
t2 = threading.Thread(target=printloop)

t1.start()
t2.start()

t2.join()

# working with events

# event = threading.Event()
# we can trigger or wait for this event

# def myfunction():
    # print("Waiting for the event to trigger...")
    # event.wait()
    # print("performing action xyz now...")

# t1 = threading.Thread(target=myfunction)
# t1.start()

# x = input("Want to trigger event?[y/n]: ")
# if x == 'y':
    # event.set()  # stop waiting for event to happend


# synchronization(semaphores)
# simliar to lock but doesn't completely locks the resources though limit the access to resource

# semaphore = threading.BoundedSemaphore(value=5)
# def access(thread_num):
    # print("thread number: ", thread_num)
    # semaphore.acquire()
    # print("{} thread number printed".format(thread_num))
    # time.sleep(3)
    # print("{} releasing thread number".format(thread_num))
    # semaphore.release()

# for thread_num in range(1, 11):
    # t = threading.Thread(target=access, args=(thread_num,))
    # t.start()
    # time.sleep(1)
# so if 5 threads have already working on resources no other will get the resource until the slot gets free

# synchronization(using lock)

# lock = threading.Lock()

# x = 8192
# def double():
    # global x, lock
    # lock.acquire()  # if lock is free it acquires or else thread waits
    # while x < 16384:
        # x *= 2
        # print(x)
        # time.sleep(0.5)
    # print("Reached maximum")
    # lock.release()

# def half():
    # global x, lock
    # lock.acquire()
    # while x > 1:
        # x /= 2
        # print(x)
        # time.sleep(0.5)
    # print("Reached minimum")
    # lock.release()

# t1 = threading.Thread(target=double)
# t2 = threading.Thread(target=half)
# t2.start()
# t1.start()




















# def hello():
    # for _ in range(50):
        # print("hello!")

# t1 = threading.Thread(target=hello)
# t1.start()

# t1.join()  # joins with the main thread(or the thread scope in which it is in)

# print("Another text")








# def func1():
    # for x in range(1000):
        # print("one")

# def func2():
    # for x in range(10000):
        # print("two")

# t1 = threading.Thread(target=func1)
# t2 = threading.Thread(target=func2)
# t1.start()
# t2.start()





# def helloworld():
    # print("hello world")

# t1 = threading.Thread(target=helloworld)
# t1.start()
