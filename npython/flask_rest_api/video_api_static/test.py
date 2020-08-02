#!/usr/bin/env python3

'''test function'''

import requests

BASE = "http://127.0.0.1:5000"

data = [
    { "Likes": 10, "Name": "Myname1", "Views": 10000 },
    { "Likes": 20, "Name": "Myname2", "Views": 10001 },
    { "Likes": 30, "Name": "Myname3", "Views": 10002 },
    { "Likes": 40, "Name": "Myname4", "Views": 10003 },
    { "Likes": 50, "Name": "Myname5", "Views": 10004 },
    { "Likes": 60, "Name": "Myname6", "Views": 10005 } ]

for i in range(len(data)):
    response = requests.put(BASE + "/video/" + str(i), data[i])
    print({i: response.json()})
print("Data inserted")

input()
print("Deleting video with id 0")
response = requests.delete(BASE + "/video/0")
# print(response.json())  we are not returning any json serialization
print(response)

input()
print("get the videos with id ")
for i in range(len(data)):
    response = requests.get(BASE + "/video/" + str(i))
    print(response.json())

# to show the mesage if something isn't found
response = requests.get(BASE + "/video/6")
print(response.json())
