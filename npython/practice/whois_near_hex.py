#!/usr/bin/env python3

'''calculate which of the two hex value pair are nearest from the given list of hex values
supports both #RGB and #RRGGBB,
'''

import math

def get_coordinates(got_hex):
    '''return the co-ordinates'''
    list_coordinates = list()
    # print("got_hex is: ", got_hex)
    if len(got_hex) == 6:
        for n in range(1, 7):
            if n % 2 == 0:
                list_coordinates.append(got_hex[n-2:n])
    elif len(got_hex) == 3:
        for code in got_hex:
            list_coordinates.append(code+code)
    return list_coordinates

def get_distance(first_hex, second_hex):
    '''get the distance'''
    rgb_point1 = get_coordinates(first_hex)
    rgb_point2 = get_coordinates(second_hex)

    first_point = list()
    second_point = list()
    for a_hex in rgb_point1:
        first_point.append(int(a_hex, 16))

    for a_hex in rgb_point2:
        second_point.append(int(a_hex, 16))

    rgb_point1.clear()
    rgb_point2.clear()

    x_distance = abs(first_point[0] - second_point[0]) ** 2
    y_distance = abs(first_point[1] - second_point[1]) ** 2
    z_distance = abs(first_point[2] - second_point[2]) ** 2
    distance_points = math.sqrt(x_distance + y_distance + z_distance)
    distance_points = format(distance_points, '.3f')
    return distance_points

number = int(input())
list_hex = [input() for _ in range(number)]

list_hex = [hex.strip('#').strip() for hex in list_hex if hex.startswith('#')]

hex_dictionary = dict()
for num, hex_num in enumerate(list_hex):
    for num_again, hex_again in enumerate(list_hex):
        if hex_num == hex_again or num_again <= num:
            continue
        hex_dictionary[("#" + str(hex_num), "#" + str(hex_again))] = get_distance(hex_num, hex_again)

# print(hex_dictionary)
shortest_distance = sorted(hex_dictionary.items(), key=lambda x: float(x[1]))[0]
# print(shortest_distance)
print(f"The hex pair with shortest distance is \"{shortest_distance[0]}\" with distance of \"{shortest_distance[1]}\".")
