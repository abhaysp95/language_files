#!/usr/bin/env python3

'''test function'''

import requests

BASE = "http://127.0.0.1:5000"

data = [
    { "likes": 10, "name": "Myname1", "views": 10000 },
    { "likes": 20, "name": "Myname2", "views": 10001 },
    { "likes": 30, "name": "Myname3", "views": 10002 },
    { "likes": 40, "name": "Myname4", "views": 10003 },
    { "likes": 50, "name": "Myname5", "views": 10004 },
    { "likes": 60, "name": "Myname6", "views": 10005 } ]

for i in range(len(data)):
    response = requests.put(BASE + "/video/" + str(i), data[i])
    print({i: response.json()})
print("Data inserted")

input()
print("get the videos with id ")
for i in range(len(data)):
    response = requests.get(BASE + "/video/" + str(i))
    print(response.json())

# to show the mesage if something isn't found
response = requests.get(BASE + "/video/6")
print(response.json())

update_data = [
    { "likes": 50, "name": "Myname3", "views": 10022 },
    { "likes": 80, "name": "Myname4", "views": 10043 },
    { "likes": 110, "name": "Myname5", "views": 10604 } ]

input()
for i in range(3):
    j = 2 + i
    response = requests.patch(BASE + "/video/" + str(j), update_data[i])
    print({j: response.json()})
# update individual
response = requests.patch(BASE + "/video/0", {"likes": 2100, "view": 5500})
print("Data Updated")

input()
print("get the videos with id ")
for i in range(len(data)):
    response = requests.get(BASE + "/video/" + str(i))
    print(response.json())

input()
for i in range(2):
    j = 3 + i
    response = requests.delete(BASE + "/video/" + str(j))
    print(response)
print("All deletion done")

input()
print("get the videos with id ")
for i in range(len(data)):
    response = requests.get(BASE + "/video/" + str(i))
    print(response.json())
