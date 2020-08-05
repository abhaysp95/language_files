#!/usr/bin/env python3

with open('1301119.jpg', 'rb') as read_file:
    with open('1301119.png', 'wb') as write_file:
        for line in read_file:
            write_file.write(line)
print("File copied to 1301119.png")

print("More control on what reading and writing")
print("Doing with chunk size of 4096")

with open('1301119.jpg', 'rb') as read_file:
    with open('13011192.png', 'wb') as write_file:
        chunk_size = 4096
        rf_chunk = read_file.read(chunk_size)
        while len(rf_chunk) > 0:
            write_file.write(rf_chunk)
            rf_chunk = read_file.read(chunk_size)
print('File copied to 13011192.png')
