import time
import requests
import threading

UPDATE_INTERVAL = 0.01

def process_requests(threads, timeout=5):
    def alive_count():
        alive = [1 if thread.is_alive() else 0 for thread in threads]
        return sum(alive)

    while alive_count() > 0 and timeout > 0:
        timeout -= UPDATE_INTERVAL
        # this is 'MainThread' sleeping everytime after checking for alive_count()
        # to confirm this, uncomment below line
        # print(f"thread name: {threading.current_thread().getName()}")
        time.sleep(UPDATE_INTERVAL)
    for thread in threads:
        print(thread.result)

class MyThread(threading.Thread):
    def __init__(self, url):
        threading.Thread.__init__(self)
        self.url = url
        self.result = f"{self.url}: Custom Timeout"

    def run(self):
        res = requests.get(self.url)
        self.result = f"{self.url}: {res.text}"
        # print(f"thread '{threading.current_thread().getName()}' is done")

urls = [
        "https://httpstat.us/200",
        "https://httpstat.us/200?sleep=4000",
        "https://httpstat.us/200?sleep=10000",
        "https://httpstat.us/400"
        ]

start = time.time()

threads = [MyThread(url) for url in urls]

for thread in threads:
    thread.setDaemon(True)
    # upon commenting above line, the thread(after the timeout) will make the
    # program wait to finish()
    thread.start()
process_requests(threads)

print(f"took {time.time() - start : 0.2f} seconds")

print("done")
