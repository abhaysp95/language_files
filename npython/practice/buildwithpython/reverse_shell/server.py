#!/usr/bin/env python3

'''
server conncetion
'''

import socket
import sys

host = None
port = None
s = None


def create_socket():
    '''creation of socket as server'''
    try:
        global host, port, s
        host = ""
        port = 9999
        s = socket.socket()
    except socket.error as err:
        print("Socket connection error: {}".format(str(err)))


# bind socket and listen for connection
def bind_socket():
    '''bind the socket and listen'''
    try:
        global host, port, s
        print("Binding the port " + str(port))
        s.bind((host, port))  # bind the port with host and open the socket
        s.listen(5)  # listen for connection and tolerate max of 5 bad connection
    except socket.error as err:
        print("Bad connection, error: {}\nRetrying...".format(str(err)))
        bind_socket()  # recursively call to bind socket on error


def accept_socket():
    '''accept the connection got from listening'''
    global s
    conn, address = s.accept()
    print("Connection Established. IP: " + address[0] + " | Port: " + str(address[1]))
    send_commands(conn)  # conn will be used everytime we want to have conversation
    conn.close()


def send_commands(conn):
    '''send commands to client'''
    global s
    while True:
        cmd = input()
        if cmd == "quit":
            conn.close()
            s.close()
            sys.exit(0)
        if len(str.encode(cmd)) > 0:
            conn.send(str.encode(cmd))
            # recieve msg in chunks of 1024
            client_response = str(conn.recv(1024), "utf-8")
            print(client_response, end='')


def main():
    '''main function'''
    create_socket()
    bind_socket()
    accept_socket()


if __name__ == "__main__":
    main()
