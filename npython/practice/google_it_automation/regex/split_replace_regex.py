#!/usr/bin/env python

import re

print(re.split(r"[.!?]", "One Sentence. Another One? And the last one!"))
print(re.split(r"([.!?])", "One Sentence. Another One? And the last one!"))

# sub for substitute

print(re.sub(r"[\w.%+-]+@[\w.-]+",
      "[REDACTED]",
      "Recieved email for go_nuts95@my.example.com"))


# a backslash followed by number reference to capture group, or can also use $1
# we can also use them as pattern that repeat themselves(backreferences)
print(re.sub(r"^([\w .-]+), ([\w .-]+)$", r"\2 \1", "Lovelace, Ada"))

string = "Tahiti Tahiti Atoll"
result = re.search(r"\b(\w+)\b\s+\1\b", string)
print("{}".format(result[1]))
result1 = re.findall(r"\b(\w+)\b\s+\1\b", string)
print(result1)
