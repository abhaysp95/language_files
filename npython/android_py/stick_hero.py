#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
checking out stick hero game android(with help of engineer-man)
"""

import sys
import numpy
import time
from ppadb.client import Client
from PIL import Image

adb = Client(host='127.0.0.1', port=5037)  # this is default
devices = adb.devices()

if len(devices) == 0:
    print('No device found')
    # quit()
    sys.exit()

device = devices[0]
# device.shell('input touchscreen swipe 400 400 400 400 150')

while True:
    scr_img = device.screencap()

    with open('screen.png', 'wb') as f:
        f.write(scr_img)

    scr_img = Image.open('screen.png')
    scr_img = numpy.array(scr_img, dtype=numpy.uint8)

# print(scr_img[1600])

    pixels = [list(x[:3]) for x in scr_img[1600]]
# print(pixels)

    transitions = []
    ignore = True
    black = True

    for i, pixel in enumerate(pixels):
        red, green, blue = [int(x) for x in pixel]
        # print(red, green, blue)

        if ignore and (red + green + blue) != 0:
            continue

        ignore = False

        # from to someother color
        if black and (red + green + blue) != 0:
            black = not black
            transitions.append(i)
            continue

        if not black and (red + green + blue) == 0:
            black = not black
            transitions.append(i)
            continue

    print(transitions)
    start, target1, target2 = transitions
    gap = target1 - start
    target = target2 - target1
    distance = (gap + target / 2) * 0.98
    print(distance)

    device.shell(f'input touchscreen swipe 500 500 500 500 {int(distance)}')

    time.sleep(2.5)
