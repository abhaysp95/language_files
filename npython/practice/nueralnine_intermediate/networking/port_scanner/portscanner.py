#!/usr/bin/env python3

'''
a simple multi-threaded port scanner
'''

import socket
import threading
from queue import Queue

IP_ADDR = "127.0.0.1"
PORT_QUEUE = Queue()
OPEN_PORTS = list()

def connect_to(port):
    '''connect to provied port'''
    try:
        # print("inside try")
        custom_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        custom_socket.connect((IP_ADDR, port))
        return True
    except OSError:
        # different exceptions for socket like
        # [socket.error, socket.herror, socket.gaierror, socket.timeout]
        # print("inside except")
        return False

def fill_port_queue(port_list):
    '''put scanned ports in this queue'''
    for port in port_list:
        PORT_QUEUE.put(port)

def worker():
    '''does the work of checking if port is opened or not'''
    while not PORT_QUEUE.empty():
        port = PORT_QUEUE.get()
        if connect_to(port):
            # print("inside worker if")
            print("Connection to port '{}' successful".format(port))
            OPEN_PORTS.append(port)

PORT_LIST_TO_SCAN = range(1, 65000)
THREAD_LIST = list()

fill_port_queue(PORT_LIST_TO_SCAN)

THREAD_COUNT = 20
for thread in range(THREAD_COUNT):
    thread_created = threading.Thread(target=worker)
    THREAD_LIST.append(thread_created)

for thread in THREAD_LIST:
    thread.start()

for thread in THREAD_LIST:
    thread.join()

print("Port Scanning done!!!")
print("Open ports are: ", OPEN_PORTS)
