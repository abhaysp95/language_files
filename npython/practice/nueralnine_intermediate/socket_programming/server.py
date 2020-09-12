#!/usr/bin/env python3

import socket

# giving internet socket and tcp
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# udp would be like socket.SOCK_DGRAM

s.bind(("127.0.0.1", 55555))  # host and port
s.listen()  # puts this in listening mode(behave like server)

while True:
    # accept all incoming connection
    client, address = s.accept()
    print("You are now connected to {}".format(address))
    # send message to the socket
    client.send("You are connected".encode("utf-8"))
    client.close()
