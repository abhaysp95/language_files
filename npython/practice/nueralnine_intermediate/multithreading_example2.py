#!/usr/bin/env python3

'''
let's look at the semaphores now
'''

# we are going to provide a count to have maximum number of threads accessible
# at a time

import threading
import time

semaphore = threading.BoundedSemaphore(value=5)  # maximum threading provided 5

def access(thread_count):
    print("Trying to access %s" % thread_count)
    semaphore.acquire()
    print("Got access to %s" % thread_count)
    time.sleep(10)  # 10 seconds before this thread has got freed
    print("Releasing %s" % thread_count)
    semaphore.release()


for i in range(1, 11):
    t = threading.Thread(target=access, args=(i,))
    t.start()
    time.sleep(1)


# so, first 5 are granted access, then the others have to wait, till first one
# got free after 10 seconds, and the 6th one got granted, same happened for the
# rest of the 5
