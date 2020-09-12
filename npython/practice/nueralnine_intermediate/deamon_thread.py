#!/usr/bin/env python3

'''
implementation of daemon thread in python
'''

import threading
import time

file = "text.txt"
text = ""

def readfile():
    global file, text
    while True:
        with open(file, 'r') as open_file:
            text = open_file.read()
        time.sleep(3)

def printfile():
    for _ in range(30):
        print(text)
        time.sleep(1)


t1 = threading.Thread(target=readfile, daemon=True)
t2 = threading.Thread(target=printfile)

t1.start()
t2.start()


# daemon thread isn't the important thread here, it'll run continuously but as soon as printfile thread is terminated the program will terminate and so does the daemon
