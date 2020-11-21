#!/usr/bin/env python3

'''
basic socket programming in python(server)
'''

import socket

# using internet socket(not unix socket) and TCP(SOCK_STREAM, UDP->SOCK_DGRAM)
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('127.0.0.1', 55555))
s.listen()  # puts our socket in listening mode

while True:
    client, address = s.accept()  # accept every request(client)
    print("Connected to address: {}".format(address))
    client.send("You're connected!".encode("UTF-8"))
