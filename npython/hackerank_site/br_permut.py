#!/usr/bin/env python3

def get_substrs(openbr, closebr, out):
    if (len(openbr) == 0 and len(closebr) == 0):
        print(out)
        return
    if (len(openbr) <= len(closebr)):
        if (len(openbr) == 0):
            out += closebr[0]
            closebr = closebr[1:]
            get_substrs(openbr, closebr, out)
        else:  # if len(openbr) <= len(closebr)
            if len(openbr) == len(closebr):
                out += openbr[0]
                openbr = openbr[1:]
                get_substrs(openbr, closebr, out)
            else:
                out1 = out + openbr[0]
                # openbr = openbr[1:]
                get_substrs(openbr[1:], closebr, out1)
                out2 = out + closebr[0]
                # closebr = closebr[1:]
                get_substrs(openbr, closebr[1:], out2)


n = int(input())

openbr = '(' * n
closebr = ')' * n

get_substrs(openbr, closebr, "")



# first check if len(openbr)
