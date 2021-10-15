from math import sqrt
import _thread as thread

def is_prime(x):
    if x < 2:
        print("%i is not a prime number" % x)
    elif x == 2:
        print("%i is a prime number" % x)
    elif x % 2:
        print("%i is not a prime number" % x)
    else:
        limit = int(sqrt(x)) + 1
        for i in range(3, limit, 1):
            if x % i == 0:
                print("%i is not a prime number" % x)
        print("%i is a prime number" % x)

my_input = [2, 193, 323, 1327, 433785907]

for x in my_input:
    thread.start_new_thread(is_prime, (x,))

_ = input("Enter something")
print("Finished")

# _thread is used in Python3 to use 'thread' module of Python2
# In the _thread module, new threads are created to execute functions concurrently. The way to do this is by using the 'thread.start_new_thread()' function.
# thread.start_new_thread(func, *args[, **kwargs])
