#!/usr/bin/env python3

def is_vowel(ch):
    return ((ch == 'a')
            or (ch == 'e')
            or (ch == 'i')
            or (ch == 'o')
            or (ch == 'u'))

tc = int(input())

for _ in range(tc):
    string = input()
    len_str = len(string)

    counter = 0
    substr = ""
    while (counter < len_str):
        if not is_vowel(string[counter]):
            counter += 1
            continue
        else:
            temp_str = ""
            while (counter < len_str):
                if (is_vowel(string[counter])):
                    temp_str += string[counter]
                    counter += 1
                else:
                    break
            if len(temp_str) > len(substr):
                substr = temp_str

    if len(substr) == 0:
        print(-1)
    else:
        print(substr)



# not so better approach(put this after len_str line and before final output printing line to test)

    # consonents = [ 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' ]
    # substr = ""
    # for idx1 in range(len_str):
        # for idx2 in range(idx1 + 1, len_str + 1):
            # temp_str = string[idx1:idx2]
            # is_consonent_present = False
            # for consonent in consonents:
                # if consonent in temp_str:
                    # is_consonent_present = True
                    # break
            # if not is_consonent_present:
                # if len(temp_str) > len(substr):
                    # substr = temp_str
