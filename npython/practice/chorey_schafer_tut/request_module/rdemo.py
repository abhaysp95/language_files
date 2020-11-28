#!/usr/bin/env python3

'''
usage: requests
'''

import requests
# import json




try:
    r = requests.get("https://httpbin.org/delay/7", timeout=3)
    print(r)
except requests.RequestException as rexcept:
    print("Timeout: ", rexcept)




# let's try using basic-auth for user authentication(other method to using form)
# r = requests.get("https://httpbin.org/basic-auth/test/testing",
                 # auth=('test', 'testing'),
                 # timeout=1)  # timeout = 1 sec, else requests will wait infinitely
# print(r.text)
# print(r)  # on wrong auth, recieved 401, correct is 200


# parameters added to URLs
# r = requests.get("https://httpbin.org/get?page=2&count=25")

# but request method can take dictionary of parameters and will generate a correct URL
# payload = {'page': 2, 'count': 25}
# r = requests.get("https://httpbin.org/get", params=payload)

# print(r.text)  # returns json
# print(r.headers)
# print(r.url)



# rp = requests.post("https://httpbin.org/post", data={'username': 'corey', 'password': 'testing'})
# print(rp.text)
# r_dict = rp.json()
# print(r_dict['form'])

# with open('gotjson.json', 'w') as file:
    # json.dump(r_dict, file, indent=4)









# r = requests.get('https://xkcd.com/353')
# print(help(r))
# print(r.text)  # gives content in unicode, so you'll get source(html) of page

# ri = requests.get("https://imgs.xkcd.com/comics/python.png")
# print(ri.content)  # get data in bytes, useful for non-text things

# with open('comic.png', 'wb') as f:
    # f.write(ri.content)

# print(r.status_code)
# print(ri.ok)  # give true if accessible(<400)
# 200s are success
# 300s are redirect
# 400s are client-side errors
# 500s are server-side errors

# print(ri.headers)  # all the header data from response
