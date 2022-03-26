# Python ships with a module that contains a number of container data types
# called Collections. We'll talk about few of them and discuss their usefulness
# The ones which we'll talk about are:
# defaultdict, OrderedDict, Counter, deque, namedtuple, enum.Enum(outside of
# the module, Python 3.4+)


# defaultdict

# Unlike 'dict', with defaultdict you do need to check whether a key is present
# or not
from collections import defaultdict

colors = (
        ("name1", "color1"),
        ("name2", "color2"),
        ("name3", "color3"),
        ("name2", "color4"),
        ("name1", "color5"),
        ("name6", "color6"))

favorite_colors = defaultdict(list)
for name, color in colors:
    favorite_colors[name].append(color)
print("favorite_colors:\n", favorite_colors)

# One other very important use case is when you are appending to nested lists
# inside a dictionary. If a key is not already present in the dictionary then
# you are greeted with a 'KeyError'. 'defaultdict' allows us to circumvent this
# issue in a clever way. First a example using 'dict' which raises 'KeyError'
# and then a solution using 'defaultdict'

# some_dict = {} # dict()
# some_dict['colors']['favorite'] = 'yellow'
# Raises KeyError: 'colors'

# solution
tree = lambda: defaultdict(tree)
some_dict = tree()
some_dict['colors']['favorite'] = 'black'
some_dict['colors']['favorite'] = 'green'
some_dict['colors']['not-favorite'] = 'pink'
some_dict['work'] = 'done'

import json
print(json.dumps(some_dict))
