#!/usr/bin/env python3

import re

my_txt = "An investment in knowledge pays the best interest"

def lettercompiler(txt):
    result = re.findall(r'([a-c]).', txt)
    return result


print(lettercompiler(my_txt))
