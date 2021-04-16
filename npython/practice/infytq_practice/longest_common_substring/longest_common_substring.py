#!/usr/bin/env python3

tc = int(input())

def get_max_common_match(str1, str2, n1, n2):
    common_str_len = 0
    for x in range(n1):
        for y in range(x + 1, n1 + 1):
            new_str = str1[x:y]
            if new_str in str2:
                common_str_len = max(common_str_len, len(new_str))
    return common_str_len

for _ in range(tc):
    str1len, str2len = list(map(int, input().split()))
    str1 = input()
    str2 = input()
    print(get_max_common_match(str1, str2, str1len, str2len))



# not so better approach(above is little better approach)
# def get_max_common_match(str1, str2):
    # match = 1
    # match_list = list()
    # for i1 in range(len(str1)):
        # match_count = 0
        # for i2 in range(len(str2)):
            # if (str1[i1] == str2[i2]):
                # match_count += 1
                # pi1 = i1
                # pi2 = i2
                # i1 += 1
                # i2 += 1
                # while((i1 != len(str1)) and (i2 != len(str2))):
                    # if (str1[i1] == str2[i2]):
                        # match_count += 1
                        # i1 += 1
                        # i2 += 1
                    # else:
                        # break
                # i1 = pi1
                # i2 = pi2
                # match_list.append(match_count)
                # match_count = 0
    # return max(match_list)
