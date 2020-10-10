#!/usr/bin/python3

import subprocess
subprocess.call("ls -l", shell=True);

cmd1 = "echo A listing of the directory content"
cmd2 = "dir -u"

cmds = [cmd1, cmd2]
for cmd in cmds:
    subprocess.call(cmd, shell=True)
