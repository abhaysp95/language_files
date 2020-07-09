#!/usr/bin/env python3

import os
import subprocess

my_env = os.environ.copy()
# my_env['FRUIT'] = os.pathsep.join(['Mango', my_env['FRUIT']])
# pathsep = ':' (for linux)
my_env['PATH'] = os.pathsep.join(['/opt/myapp/', my_env['PATH']])

# run() creates a child process
result = subprocess.run(["myapp"], env=my_env)
# some other parameters of run()
# cwd=change working dir
# timeout=stop command exec if given time completes
# shell=create a new shell and run command in it

# print(my_env['FRUIT'])
