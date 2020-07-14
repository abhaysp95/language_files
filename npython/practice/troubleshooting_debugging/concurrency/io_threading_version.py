#!/usr/bin/env python3

'''
performing the same task as io_non_cuncurrent but with threading
to I/O bound
'''

from concurrent import futures
import requests
import threading
import time

thread_local = threading.local()


def get_session():
    '''create session for one per thread'''
    # we can also use try and except block but hasattr is more readable
    if not hasattr(thread_local, "session"):
        # so, creating a new session for each thread(here, 6 times)
        thread_local.session = requests.Session()
    return thread_local.session


def download_site(url):
    '''download a site'''
    # each thread needs to create its own requests.Session()
    # because unfortunately, requests.Session() is not thread-safe
    # as OS is in control of when your task gets interrupted and another task
    # starts, any data shared between the threads need to be protected, or
    # thread-safe
    session = get_session()
    with session.get(url) as response:
        print(f"Read {len(response.content)} from {url}")

# some strategies to make data access thread safe(depends on usage):
# using thread-safe data-structure like Queue from Python's queue module
# or something like thread local storage. 'Threading.local()' creates
# an object that look like a global but is specific to each individual thread
# In here, this is done with thread_local and get_session()


def download_all_sites(sites):
    '''call download_site with threading'''
    with futures.ThreadPoolExecutor(max_workers=6) as executor:
        # creating 6 threads in pool
        # map function in executor just behaves like map() function
        executor.map(download_site, sites)


def main():
    sites = ["https://www.jython.org",
             "http://olympus.realpython.org/dice", ] * 80
    start_time = time.time()
    download_all_sites(sites)
    duration = time.time() - start_time
    print(f"Downloaded {len(sites)} in {duration} seconds")


if __name__ == "__main__":
    main()


# threads can interact in ways that are subtle and hard to detect.
# These interactions can cause race conditionss that frequently
# result random, intermittent bugst that can be quite difficult to
# find
