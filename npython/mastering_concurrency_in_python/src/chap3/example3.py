from math import sqrt
import threading

class MyThread(threading.Thread):
    def __init__(self, x):
        threading.Thread.__init__(self)
        self.x = x

    def run(self):
        print("Start processing %i..." % self.x)
        is_prime(self.x)

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

threads = []

for x in my_input:
    thread = MyThread(x)
    thread.setName(str(x))
    thread.start()
    threads.append(thread)

for thread in threads:
    print("joining", thread.getName())
    thread.join()
# joining can be done any time after the thread execution is started. Even
# though all the theads are executed if not all joined threads are finished executing, the
# program will not move forward

print("Finished")
