#!/usr/bin/env python3

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', 55555))  # connect to the specified server
message = s.recv(1024)  # recieve 1024 bytes of data
s.close()
print(message.decode('utf-8'))
