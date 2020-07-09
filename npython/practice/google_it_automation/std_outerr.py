#!/usr/bin/env python3

import subprocess
import os

if not os.path.isdir('std_stream'):
    os.mkdir('std_stream')

with open('std_stream/out_stream.txt', 'w+') as fout:
    with open('std_stream/err_stream.txt', 'w+') as ferr:
        # if you want to capture error use check_call()
        out = subprocess.call(["ls", "-lha"], stdout=fout, stderr=ferr)
        # reset file to read from it
        fout.seek(0)
        ferr.seek(0)

        # save output in variable
        output = fout.read()
        errors = ferr.read()

print('Output String:\n ' + output)
print('Error String:\n' + errors)
