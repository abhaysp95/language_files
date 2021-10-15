import requests

url = "https://archlinux.org"

res = requests.get(url)

print(res.status_code)
print(res.headers)

with open('archlinux.html', 'w') as file:
    file.write(res.text)

print("done")
