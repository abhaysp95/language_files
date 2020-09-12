#!/usr/bin/env python3

'''
basic implementation of how event works in threading in python
'''

import threading

event = threading.Event()

def process():
    print("Waiting for event to trigger...")
    event.wait()
    print("Performing operation xyz...")

t1 = threading.Thread(target=process)
t1.start()

x = input("Do you want to trigger the event(y/n)?")
if x == "y":
    event.set()

# if you press something other than y, than event is still waiting
