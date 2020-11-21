#!/usr/bin/env python3

'''
server for tcp chatroom
'''

import socket
import threading
import sys

IP_ADDR = '127.0.0.1'
PORT = 44444

try:
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((IP_ADDR, PORT))
    server.listen()
except OSError as ose:
    print("can't start the server: ", ose)
    sys.exit(1)

clients = list()
usernames = list()

def broadcast_message(message):
    '''broadcast message to all the clients'''
    for client in clients:
        client.send(message)

def handle_client(client):
    '''handle the operations from clients'''
    while True:
        try:
            message = client.recv(1024).decode('UTF-8')
            broadcast_message(message)
        except OSError:
            index = clients.index(client)
            clients.remove(client)
            remove_username = usernames[index]
            client.close()  # close the connection
            print(f"User {remove_username} exited the chatroom!!!")
            usernames.remove(remove_username)
            break

def recieve_clients():
    '''recieve the requesting clients messages'''
    while True:
        try:
            client, address = server.accept()  # accept incoming requests
            print(f"Connection with {address} established")

            client.send("Username".encode('UTF-8'))
            got_username = client.recv(1024).decode('UTF-8')
            usernames.append(got_username)
            clients.append(client)

            print(f"Username of {client} is {got_username}")
            broadcast_message(f"{got_username} joined the chatroom".encode('UTF-8'))
            client.send("Connection to Server established".encode('UTF-8'))

            thread = threading.Thread(target=handle_client, args=(client,))
            thread.start()
        except KeyboardInterrupt:
            print("\nServer closed unexpectedly")
            sys.exit(1)

print("Server is now listening...")
recieve_clients()
