#!/usr/bin/env python3

values = ["823", "863"]
num = values[0][0:]
for row in range(0, len(values)):
    print("row: ", row)
    for column in range(0, len(values[row])):
        print("column: ", column)
        print("num before if: ", num)
        print("value: ", values[row][column:])
        if num > values[row][column:]:
            num = values[row][column:]
            print("num after if: ", num)
print(num)
