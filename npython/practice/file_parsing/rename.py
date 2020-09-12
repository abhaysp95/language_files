#!/usr/bin/env python3

import os

os.chdir('/home/raytracer/Documents/npython/practice/file_parsing')

for content in os.listdir():
    f_name, f_ext = os.path.splitext(content)
    if f_ext == ".mp4":
        f_title, f_course, f_num = f_name.split('-')
        f_title = f_title.strip()
        f_course = f_course.strip()
        # zfill for padding, param = how wide you want the string to be
        f_num = f_num.strip()[1:].zfill(2)

        new_name = '{}-{}-{}{}'.format(f_num, f_course, f_title, f_ext)
        os.rename(content, new_name)
