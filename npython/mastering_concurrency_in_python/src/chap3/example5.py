# in this example, we have implemented the structure: a task queue that holds
# all the tasks to be executed and a thread pool(thread A, B and C) that
# interacts with the queue to process its elements individually

import queue
import threading
import time

class MyThread(threading.Thread):
    def __init__(self, name):
        threading.Thread.__init__(self)
        self.name = name

    def run(self):
        print("Starting thread %s" % self.name)
        process_queue()
        print("Exiting thread %s" % self.name)

def process_queue():
    while True:
        try:
            # remove and return item from queue
            x = my_queue.get(block=False)
        except queue.Empty:
            return
        else:
            print_factors(x)
        time.sleep(1)

def print_factors(x):
    result_string = f"{threading.currentThread().getName()} Positive factors of {x} are:"
    for i in range(1, x + 1):
        if x % i == 0:
            result_string += str(i) + ' '
    result_string += '\n' + '_' * 20
    print(result_string)

# setting up variables
input_ = [1, 10, 4, 3]

# filling the queue
my_queue = queue.Queue()

for x in input_:
    my_queue.put(x)

# initializing and starting 3 threads
thread1 = MyThread('A')
thread2 = MyThread('B')
thread3 = MyThread('C')

thread1.start()
thread2.start()
thread3.start()

thread1.join()
thread2.join()
thread3.join()

print("Done")
