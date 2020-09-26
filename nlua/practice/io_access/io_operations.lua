#!/usr/bin/lua5.3


line = io.read()  -- will take input from stdin
print("printing: ", line)

line = io.read(4)  -- read upto 15 characters
-- this means it only also take carraige return as input until 4 chars are not done
print("printing: ", line)

print("\n\n")

io.write("let's check \t if it takes \b new-line char or not\n")
-- what will \r do in lua ?
io.write("can", "have", "mulitple", "args", 34.239, "and int(which is changed to string)")
-- point to noted that "io.write" will not add tabs between args for seperation
