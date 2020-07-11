#!/usr/bin/env python3


def character_frequency(filename):
    '''counts the frequency of character in the given file'''
    try:
        fname = open(filename, 'r')
    # except OSError:
        # return None
    except FileNotFoundError:
        return "File Not Found"

    characters_dict = dict()
    for line in fname:
        line = line.strip()
        for char in line:
            characters_dict[char] = characters_dict.get(char, 0) + 1
    fname.close()
    return characters_dict


if __name__ == "__main__":
    res_dict = character_frequency('../filetocopy.txt')
    print(res_dict)
