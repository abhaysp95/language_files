#!/usr/bin/env python3

rows = int(input())
# take matrix input
matrix = list()
for _ in range(rows):
    row = [int(x) for x in input().split()]
    matrix.append(row)

vals = set()

def print_matrix(fmatrix):
    for row in fmatrix:
        print(row)

def get_val(fmatrix):
    matched_val = set()

    # check horizontally(in column)
    for row in fmatrix:
        match_count = 0
        prev_num = -1
        for num in row:
            if (num == prev_num):
                match_count += 1
            prev_num = num
            if (match_count == 3):
                matched_val.add(num)

    # check vertically(by row)
    for col_idx in range(len(fmatrix[0])):
        match_count = 0
        prev_num = -1
        for row in fmatrix:
            if (row[col_idx] == prev_num):
                match_count += 1
            prev_num = row[col_idx]
            if (match_count == 3):
                matched_val.add(row[col_idx])

    # check diagonally
    match_count = 0
    prev_num = -1
    for idx in range(4):
        if (fmatrix[idx][idx] == prev_num):
            match_count += 1
        prev_num = fmatrix[idx][idx]
        if (match_count == 3):
            matched_val.add(fmatrix[idx][idx])

    # check reverse diagonal
    match_count = 0
    prev_num = -1
    for idx in range(4):
        if (fmatrix[idx][3 - idx] == prev_num):
            match_count += 1
        prev_num = fmatrix[idx][3 - idx]
        if (match_count == 3):
            matched_val.add(fmatrix[idx][3 - idx])

    return matched_val


# form matrix of 4x4
for row_idx in range(rows - 3):
    for col_idx in range(len(matrix[0]) - 3):
        row_count = row_idx
        temp_matrix = list()
        while (row_count < 4 + row_idx):
            row = list()
            for x in range(4):
                row.append(matrix[row_count][col_idx + x])
            temp_matrix.append(row)
            row_count += 1
        # print(temp_matrix)
        # print("-----------------------")
        got_vals = get_val(temp_matrix)
        # print("vals: ", got_vals)
        for val in got_vals:
            vals.add(val)

if (len(vals) == 0):
    print("-1")
else:
    print(sorted(vals)[0])  # print minimum
