#!/usr/bin/env python3

''' using external json file '''

import json

# load method loads a file in python object, and loads method loads a string
# same as above line for dump() and dumps()
with open('states.json', 'r') as jfile:
    data = json.load(jfile)

for state in data['states']:
    print(state['name'], state['abbreviation'])

# let's remove something and write in new file
for state in data['states']:
    del state['area_codes']

with open('new_states.json', 'w') as jfile:
    json.dump(data, jfile, indent=4)
