#!/usr/bin/env python
import os
import subprocess
from multiprocessing import Pool

home = os.path.expanduser("~")
src = home + "/data/prod/"
dest = home + "/data/prod_backup/"

def run(dirname):
    print("moving {} from {} to {}".format(dirname, src, dest))
    subprocess.call(["rsync", "-arq", src + dirname, dest])


if __name__ == "__main__":
    for (root, dirs, filename) in os.walk(home + src, topdown=True):
        break  # only first level

    p = Pool(len(dirs))  # create pool of multiprocessing with len of dirs
    p.map(run, dirs)
