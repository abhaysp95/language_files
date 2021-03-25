#!/usr/bin/env python3

def procedural(val1):
    try:
        sum1 = 0
        for item in str(val1):
            sum1 += int(item)
    except TypeError:
        print("TypeError occurred")
    finally:
        print("Finally in function")
    print("Function executed successfully")

try:
    procedural(792)
    print("Try handled")
except ValueError:
    print("Value error occurred")
except NameError:
    print("Name error occurred")
finally:
    print("Finally in main")


# Note: finally block executes every time, whereas else block only executes when
# try block succeeds
