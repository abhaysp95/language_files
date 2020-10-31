#!/usr/bin/env python3

""" let's see a real world usage example for json """

import json
from urllib.request import urlopen

with urlopen(
    "https://finance.yahoo.com/webservice/v1/symbols/allcurrencies/quote?format=json"
) as response:
    source = response.read()

print(source)
