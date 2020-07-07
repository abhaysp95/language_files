#!/usr/bin/env python3

import re

string = "A completely different string that also has numbers [34567]"
string2 = "99 elephants in a [cage]"

# checking the same regex pattern with these two
print(re.search(r"\[(\d+)\]", string))
print((re.search(r"\[(\d+)\]", string))[0])
print((re.search(r"\[(\d+)\]", string))[1])
print(re.search(r"\[(\d+)\]", string2))


def extract_pid(log_line):
    regex = r"\[(\d+)\]"
    result = re.search(regex, log_line)
    if result is None:
        return ''
    return result[1]


print("\nfunction from here\n")
print(extract_pid(string))
print(extract_pid(string2))


def extract_pid(log_line):
    regex = r"\[(\d+)\]:\s([A-Z]+)"
    result = re.search(regex, log_line)
    if result is None:
        return None
    return "{} ({})".format(result[1], result[2])


print(extract_pid("July 31 07:51:48 mycomputer bad_process[12345]: ERROR Performing package upgrade")) # 12345 (ERROR)
print(extract_pid("99 elephants in a [cage]")) # None
print(extract_pid("A string that also has numbers [34567] but no uppercase message")) # None
print(extract_pid("July 31 08:08:08 mycomputer new_process[67890]: RUNNING Performing backup")) # 67890 (RUNNING)
