#!/usr/bin/env python3

'''
examples of Popen, run basically uses Popen underneath
'''

import subprocess as sp
import os


def popen_wait():
    p = sp.Popen(["ls", "-lha"])
    p.wait()  # causes the program to block until the subprocess returns


def store_output_and_error():
    p = sp.Popen(
        ["ls", "-lha"],
        stdout=sp.PIPE,
        stderr=sp.PIPE,
        universal_newlines=True
    )
    # send data to stdin
    # read data from stdout and stderr, until EOF
    # optional args => input=None, timeout=None
    # input arg should be data to be sent to the child process, it'll be string
    # otherwise, it must be byte
    output, errors = p.communicate()  # returns tuple with output and error
    print('Output is:\n ', output)
    print('Error is:\n ', errors)


def redirect_output_to_file():
    output_file = 'std_stream/redirect_Popen.txt'
    myoutput = open(output_file, 'w+')
    p = sp.Popen(
        ["ls", "-lha"],
        stdout=myoutput,
        stderr=sp.PIPE,
        universal_newlines=True
    )

    # if you want to send data to the process's stdin, you need to create Popen
    # object with stdin=PIPE. Similarily, to get anything other than None in
    # the result tuple, you need to give stdout=PIPE and/or stderr=PIPE too.
    output, errors = p.communicate()
    print('Output is:\n ', output)
    print('Error is:\n ', errors)
    print('Args is:\n', p.args)
    print('Process ID:\n', p.pid)

    print('Reading saved file:\n')
    with open(output_file, 'r') as file:
        print(file.read())
    # in same way, there's p.stdin, p.stdout, p.stderr, if the attribute is
    # readable, writeable and writeable stream object returned by open()


def stdout_stderr_to_same_file():
    output_file = 'std_stream/another_redirect_Popen.txt'

    myoutput = open(output_file, 'w+')
    p = sp.Popen(
        ["ls", "foo bar"],
        stdout=myoutput,
        stderr=myoutput,
        universal_newlines=True
    )
    output, errors = p.communicate()
    # nothing here because we didn't send stdout to subprocess.PIPE
    print('Output is:\n ', output)
    # nothing here either
    print('Error is:\n ', errors)

    with open(output_file, "r") as file:
        print(file.read())


def give_input_to_script():
    '''a simple shell script which takes input through subprocess
    and gives sum of it'''
    if not os.path.isfile('asum.sh'):
        print("File {} not found".format('asum.sh'))
        with open('asum.sh', 'w+') as file:
            file.write("""
                       #!/usr/bin/env sh

                       read fnum
                       read snum
                       printf \"%d\" \"$(( fnum + snum ))\"
                       """)
    else:
        print("File {} found".format('sum.sh'))

    print("Checking File Permission")
    print("Should be greater than or equal to 744")
    current_perm = oct(os.stat('asum.sh').st_mode & 0o777)
    print("Current File permission is: {}".format(current_perm))

    if int(oct(os.stat('asum.sh').st_mode)[-3:]) < 744:
        print('Setting Permission to 754')
        os.chmod('asum.sh', 0o754)  # 0o changes number to octal
    print('Proceeding further')

    sum_proc = sp.Popen(
        ["sh", "asum.sh"],
        stdin=sp.PIPE,  # to take input through communicate
        stdout=sp.PIPE,  # to show output from output stream
        stderr=sp.PIPE  # to show error from std_err stream
        # universal_newlines=True
    )
    # communicate only communicate ones, it waits until the end of process like
    # run etc.
    output, errors = sum_proc.communicate(b"10\n20\n")  # sending input as byte
    print("Output is:\n %d" % int(output.decode()))
    if errors == '':
        print('No Errors')
    else:
        print('Error is:\n ', errors.decode())


# store_output_and_error()
# redirect_output_to_file()
# stdout_stderr_to_same_file()
give_input_to_script()
