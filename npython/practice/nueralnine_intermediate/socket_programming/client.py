#!/usr/bin/env python3

'''
basic socket programming in python(client)
'''

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', 55555))  # connect to server


message = s.recv(1024)  # how many bytes of message to get
s.close()
print(message.decode('UTF-8'))
