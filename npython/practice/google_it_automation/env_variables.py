#!/usr/bin/env python3

import os

# D.get(k[,d]), D[k] if k in D else return d
print("home: " + os.environ.get("HOME", 'Not Found'))
print("shell: " + os.environ.get("SHELL", 'Not Found'))
print("fruit: " + os.environ.get("FRUIT", 'Not Found'))
# not working
print("Checking Error: " + os.environ.get("?", "Wrong"))
