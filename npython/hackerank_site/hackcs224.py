#!/usr/bin/env python

a = int(input())
flag = 0

if (a > 1 and a != 1):
    i = 2
    while (i < a//2):
        n = a%i
        if (n == 0):
            flag = 1
            break

    if (a == 2):
        print("prime")
    else:
        if(flag == 1):
            print("not prime")
        else:
            print("prime")


