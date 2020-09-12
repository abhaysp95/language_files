#!/usr/bin/env python3

import subprocess

res = subprocess.Popen(['uname', '-srv'], stdout=subprocess.PIPE)
uname = res.stdout.read().strip()
uname = uname.decode('utf-8')
print(uname)
