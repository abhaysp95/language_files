#!/usr/bin/env python3

'''
socket()
'''

# socket() function in turn returns a socket object. Calling the
# socket() factory function with no arguments returns a socket object
# with sensible defaults - a TCP/IP socket:

import socket

s = socket.socket()
s.connect(("192.168.43.165", 80))
print(s.send(b"GET / HTTP/1.0\n\n"))
print(s.recv(200))
s.close()
