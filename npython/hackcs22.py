#!/usr/bin/env python
a=int(input())
if a%3==0 and a%5==0:
    print ("Zoom")
elif a%3==0:
    print ("Zip")
elif a%5==0:
    print ("Zap")
else:
    print ("Invalid")
