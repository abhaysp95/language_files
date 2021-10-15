import threading
import requests

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
        "https://httpstat.us/200?sleep=10000",
        "https://httpstat.us/400"
        ]

threads = [MyThread(url) for url in urls]

for thread in threads:
    thread.start()
for thread in threads:
    thread.join()
for thread in threads:
    print(thread.result)

print("done")
