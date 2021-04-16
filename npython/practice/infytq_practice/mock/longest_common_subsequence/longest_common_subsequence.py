#!/usr/bin/env python3

def read_char_matrix(cmatrix, string, i, j, outstr):
    if i == 0 or j == 0:
        return
    if cmatrix[i][j] == 'D':
        read_char_matrix(cmatrix, string, i - 1, j - 1, outstr)
        # print(string[i - 1], end="")
        # outstr += string[i - 1]
        outstr.append(string[i - 1])
    elif cmatrix[i][j] == 'U':
        read_char_matrix(cmatrix, string, i - 1, j, outstr)
    else:
        read_char_matrix(cmatrix, string, i, j - 1, outstr)

str1 = input()
str2 = input()

str1len = len(str1)
str2len = len(str2)

num_matrix = [[-1 for _ in range(str2len + 1)] for _ in range(str1len + 1)]
char_matrix = [[-1 for _ in range(str2len + 1)] for _ in range(str1len + 1)]

# common_str = ""
# prev_value = 0
for i in range(str1len + 1): # (0, 8)
    # common_char = ""
    for j in range(str2len + 1): # (0, 7)
        if i == 0 or j == 0:
            num_matrix[i][j] = 0
        else:
            if str1[i - 1] == str2[j - 1]:
                num_matrix[i][j] = 1 + num_matrix[i - 1][j - 1]
                char_matrix[i][j] = 'D'
            else:
                if num_matrix[i - 1][j] >= num_matrix[i][j - 1]:
                    num_matrix[i][j] = num_matrix[i - 1][j]
                    char_matrix[i][j] = 'U'
                else:
                    num_matrix[i][j] = num_matrix[i][j - 1]
                    char_matrix[i][j] = 'L'

# for row in num_matrix:
    # print(row)
# for row in char_matrix:
    # print(row)
# print(num_matrix[i][j])
outstr = list()
read_char_matrix(char_matrix, str1, str1len, str2len, outstr)
print(("".join(outstr)).strip())



            # if str1[i - 1] == str2[j - 1]:
                # num_matrix[i][j] = 1 + num_matrix[i - 1][j - 1]
                # if common_char == "":
                    # if prev_value != num_matrix[i][j]:
                        # common_char = str2[j - 1]
                        # prev_value = num_matrix[i][j]
            # else:
                # num_matrix[i][j] = max(num_matrix[i][j - 1], num_matrix[i - 1][j])
