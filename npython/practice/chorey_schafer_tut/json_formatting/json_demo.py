#!/usr/bin/env python3

''' Javascript Object Notation '''

import json

people_string = '''
{
    "people": [
        {
            "name": "John Smith",
            "phone": "629-923-9234",
            "emails": ["johnsmith@bogusemail.com", "john.smith@work-place.com"],
            "has-license": false
        },
        {
            "name": "Jane Doe",
            "phone": "932-939-1823",
            "emails": null,
            "has-license": true
        }
    ]
}
'''

# so the above json is just like dictionary, key "people" have an
# array(list) of two objects, and then those objects have key-value
# thing

data = json.loads(people_string)
print(data)
print(type(data))

# when we load json into python object, it uses following conversion table:
# L.H.S => json
# R.H.S => python

# object       => dict
# arrays       => list
# string       => str
# number(int)  => int
# number(real) => float
# true         => True
# false        => False
# null         => None

print(type(data['people']))

for person in data['people']:
    print(person['name'])

# till now we have done from json to python, let's now do vice-versa
# remove phone number and then dump it as json again

for person in data['people']:
    del person['phone']  # deletes phone key and value

new_string = json.dumps(data, indent=4, sort_keys=True)
print(new_string)
