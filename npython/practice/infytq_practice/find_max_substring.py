#!/usr/bin/env python3

"""
Given string, find the substring, conditions:
1. substring must be the longest one of all the possible substrings in the given string
2. There must not be any repeating characters in the substring
3. If there is more than one substring satisfying above two condition, then print first occuring one
4. Length of substring must be minimum
"""

def check_duplicate(string):
    for c in string:
        count = string.count(c)
        if count > 1:
            return False
        return True

def getSubString(string):
    'get the substring'
    substrings = list()
    count = 0
    print("string is: ", string)
    while count < len(string):
        substr1 = string[count:]
        if check_duplicate(substr1):
            if substr1 not in substrings and len(substr1) > 3:
                substrings.append(substr1)
            else:
                count2 = 1
                while count2 <= len(substr1):
                    substr2 = substr1[:-count2]
                    if check_duplicate(substr2):
                        if substr2 not in substrings and len(substr2) > 3:
                            substrings.append(substr2)
                    count2 += 1
        count += 1
    return substrings

def getSubStringsForMultipleString(strings):
    for string in strings:
        substrings = getSubString(string)
        # print('printing substrings')
        max_len = len(substrings[0])
        word = substrings[0]
        for substring in substrings:
            # print('substring: ', substring)
            if max_len < len(substring):
                max_len = len(substring)
                word = substring
                print(word)

def main():
    strings = [
    'hippopotamus',
    'rhinocorus',
    'mathematics',
    'winterbear',
    'kamehameha'
    ]
    getSubStringsForMultipleString(strings)

if __name__ == "__main__":
    main()
