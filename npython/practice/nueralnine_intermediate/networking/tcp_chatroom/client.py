#!/usr/bin/env python3

'''
client for tcp chatroom
'''

import socket
import threading

IP_ADDR = '127.0.0.1'
PORT = 44444

username = ""

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((IP_ADDR, PORT))

def recieve_messages():
    '''handle incoming of messages and send back'''
    global username
    while True:
        try:
            message = client.recv(1024).decode('UTF-8')
            if message == 'Username':
                username = input("Provide a username: ")
                client.send(username.encode('UTF-8'))
            else:
                print(message)
        except OSError:
            print("Some error occured!!!")
            client.close()
            break

def print_message():
    '''wait for the next input and print it'''
    global username
    while True:
        message = f"{username}: {input()}"
        client.send(message.encode("UTF-8"))

recieve_messages_thread = threading.Thread(target=recieve_messages)
recieve_messages_thread.start()

print_message_thread = threading.Thread(target=print_message)
print_message_thread.start()
