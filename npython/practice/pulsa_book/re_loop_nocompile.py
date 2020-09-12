#!/usr/bin/env python3

import re
import os

def run_re():
    pattern = "General"

    home = os.path.expanduser('~')
    infile = open(home + "/Documents/LICENSE", 'r')
    match_count = 0
    lines = 0
    for line in infile:
        match = re.search(pattern, line)
        if match:
            match_count += 1
        lines += 1
    return (lines, match_count)


if __name__ == "__main__":
    lines, match_count = run_re()
    print("Lines: ", lines)
    print("Match Count: ", match_count)
