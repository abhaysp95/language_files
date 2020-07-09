#!/usr/bin/env python3

import subprocess

def capture_output():
    process = subprocess.run(
        ['ls', '-lha'],
        check=True,  # error handling
        stdout=subprocess.PIPE,  # wait
        universal_newlines=True  # make escape characters perform their work
    )
    output = process.stdout
    print(output)


def rawstring_shell():
    # don't use this if your string uses user input,
    # as they may inject arbitrary code!
    process = subprocess.run(
        'ls -lha',
        shell=True,  # makes command perform in new child shell
        # by default run() doesn't raise an exception if the underlying process errors!
        # check=True to force
        check=True,
        stdout=subprocess.PIPE,
        universal_newlines=True
    )
    output = process.stdout
    print(output)


def check_error():
    cp = subprocess.run(
        ["ls", "foo bar"],
        universal_newlines=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    # print(cp.output)
    print(cp.stderr)
    print(cp.returncode)


def check_error2():
    '''throws error no matter what'''
    try:
        cp = subprocess.run(
            ["xxxx", "foo bar"],
            universal_newlines=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )
    except FileNotFoundError as e:
        print(e)
        print('Exit code: ', cp.returncode)


# rawstring_shell()
# check_error()
check_error2()
