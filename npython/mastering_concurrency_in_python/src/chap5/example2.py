import requests

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

for url in urls:
    ping(url)

print("done")
