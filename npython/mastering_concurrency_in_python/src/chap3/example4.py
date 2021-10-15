# one of the most common ways to apply thread synchronization is through the implementation of a locking mechanism. In our 'threading' module, the 'threading.Lock' class provides a simple and intuitive approach to creeating and working with locks. Its main usage includes the following methods:
# * 'threading.Lock()': initializes and returns a new lock object
# * 'acquire(blocking)': when this method is called, all of the threads will run
#     * the optional argument 'blocking' allows us to specify whether the current thread should wait to acquire the lock
#     * when 'blocking = 0', the current thread does not wait for the lock and simply returns 0 if the lock can't be acquired by the thread, or 1 otherwise
#     * when 'blocking = 1', the current thread blocks and waits for the lock to be released and acquires it afterwards
# * 'release()': when this method is called, the lock is released

import threading
import time

class MyThread(threading.Thread):
    def __init__(self, name, delay):
        threading.Thread.__init__(self)
        self.name = name
        self.delay = delay

    def run(self):
        print("Starting thread %s" % self.name)
        thread_lock.acquire(True)  # optional arg, no arg means 'True'(1)
        thread_count_down(self.name, self.delay)
        print("Finished thread %s" % self.name)
        thread_lock.release()

def thread_count_down(name, delay):
    counter = 5
    while counter:
        time.sleep(delay)
        print("Thread %s is counting down: %i..."
                % (name, counter))
        counter -= 1

thread_lock = threading.Lock()

thread1 = MyThread('A', 0.5)
thread2 = MyThread('B', 0.5)

thread1.start()
thread2.start()

thread1.join()
thread2.join()

print("Finished")
