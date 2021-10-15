import threading
import requests
import time

class MyThread(threading.Thread):
    def __init__(self, url):
        threading.Thread.__init__(self)
        self.url = url
        self.result = None

    def run(self):
        res = requests.get(self.url)
        self.result = f"{self.url}: {res.text}"

urls = [
        "https://httpstat.us/200",
        "https://httpstat.us/400",
        "https://httpstat.us/404",
        "https://httpstat.us/408",
        "https://httpstat.us/500",
        "https://httpstat.us/524"
        ]

start = time.time()

threads = [MyThread(url) for url in urls]

for thread in threads:
    thread.start()
    # don't put thread.join() here, because then program will behave
    # sequentially(as it'll wait for every thread to finish up before starting
    # next thread)
for thread in threads:
    thread.join()  # wait for the thread to finish up
for thread in threads:
    print(thread.result)

print(f"Took {time.time() - start : 0.2f} seconds")
