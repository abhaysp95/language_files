#!/usr/bin/env python3

'''
we'll download some sites and see I/O bound operation with
non-cuncurrent version
'''

import requests
import time


def download_site(url, session):
    '''downlaod a url'''
    # it's possible to simply use get() from requests directly,
    # but creating a Session object allows requests to do some fancy networking
    # tricks and really speed things up
    with session.get(url) as response:
        print(f"Read {len(response.content)} from {url}")


def download_all_sites(sites):
    '''create the requests session'''
    with requests.Session() as session:
        for url in sites:
            download_site(url, session)


def main():
    '''main function'''
    sites = ["https://www.jython.org",
             "http://olympus.realpython.org/dice", ] * 80
    start_time = time.time()
    download_all_sites(sites)
    duration = time.time() - start_time
    print(f"Downloaded {len(sites)} in {duration} seconds")


if __name__ == "__main__":
    main()
