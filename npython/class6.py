#!/usr/bin/env python

# swap two values by using ^ operator

a=int(input("Enter first no.: "))
b=int(input("Enter second no.: "))
if (a^b) is 1:
    a,b=b,a
    print("i'm in if")
    print ("a = ",a)
    print ("b = ",b)
else:
    print ("a = ",a)
    print ("b = ",b)
    print("i'm in else")

