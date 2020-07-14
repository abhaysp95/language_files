#!/usr/bin/env python3

from concurrent import futures
import time


def wait_on_b():
    time.sleep(5)
    # b will never complete because it's waiting on a
    print(b.result())
    return 5


def wait_on_a():
    time.sleep(5)
    # a will never complete because it's waiting on b
    print(a.result())
    return 6


def wait_on_future():
    f = executor1.submit(pow, 5, 2)
    # this will never complete because there is only one worker thread and it's
    # executing this function
    print(f.result())


executor = futures.ThreadPoolExecutor(max_workers=2)
a = executor.submit(wait_on_b)
b = executor.submit(wait_on_a)

executor1 = futures.ThreadPoolExecutor(max_workers=1)
f = executor1.submit(wait_on_future)


# There's also ProcessPoolExecutor submodule
