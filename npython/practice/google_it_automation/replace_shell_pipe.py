#!/usr/bin/env python3

'''
functionality of shell pipe
$(df -h | grep sda)
'''

import subprocess
import shlex


before_pipe = "df -h"
after_pipe = 'grep -v "sda"'
# p1 = subprocess.Popen(["df", "-h"], stdout=subprocess.PIPE)
# p2 = subprocess.Popen(["grep", "sda"], stdin=p1.stdout, stdout=subprocess.PIPE)
p1 = subprocess.Popen(shlex.split(before_pipe), stdout=subprocess.PIPE)
p2 = subprocess.Popen(shlex.split(after_pipe), stdin=p1.stdout, stdout=subprocess.PIPE)
p1.stdout.close()
output = p2.communicate()[0]

print(output.decode())
