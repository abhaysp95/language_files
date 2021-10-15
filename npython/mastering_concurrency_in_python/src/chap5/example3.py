import threading
import requests
import time

def ping(url):
    res = requests.get(url)
    print(f"{url}: {res.text}")

urls = [
        "https://httpstat.us/200",
        "https://httpstat.us/400",
        "https://httpstat.us/404",
        "https://httpstat.us/408",
        "https://httpstat.us/500",
        "https://httpstat.us/524"
        ]

start = time.time()
for url in urls:
    ping(url)
print(f"sequential: {time.time() - start : 0.2f} seconds")

print()

start = time.time()
threads = []
for url in urls:
    thread = threading.Thread(target=ping, args=(url,))
    threads.append(thread)
    thread.start()
for thread in threads:
    thread.join()

print(f"threading: {time.time() - start : 0.2f } seconds")
