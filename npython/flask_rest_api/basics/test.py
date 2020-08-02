#!/usr/bin/env python3

'''send request'''

import requests


BASE = "http://127.0.0.1:5000"

# send get request to the url
response_get = requests.get(BASE + "/helloworld/yourname/10")
# response_post = requests.post(BASE + "/helloworld")
print(response_get.json())
# print(response_post.json())
