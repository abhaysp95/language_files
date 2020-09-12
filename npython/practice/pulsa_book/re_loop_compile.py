#!/usr/bin/env python3

import re
import os

def run_re():
    pattern = 'General'
    re_obj = re.compile(pattern)

    home = os.path.expanduser("~")
    infile = open(home + "/Documents/LICENSE", 'r')
    match_count = 0
    lines = 0
    for line in infile:
        match = re_obj.search(line)
        if match:
            match_count += 1
        lines += 1
    return (lines, match_count)


if __name__ == "__main__":
    lines, match_count = run_re();
    print("Lines: ", lines)
    print("Match count: ", match_count)

# so compiled version is faster. Make habit of using compiled regular expression
# use findall() and finditer() to see, what did my pattern match?
# finditer() is more flexible, since it returns an iterator.
# use search() and match() to see, did my pattern match?
