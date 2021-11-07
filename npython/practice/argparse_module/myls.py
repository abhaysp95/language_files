import argparse

import os
import sys

# create the parser
my_parser = argparse.ArgumentParser(prog='myls', # by default, it takes sys.argv[0]
        usage="%(prog)s [options] path",  # overwrites standard help format
        description="List the content of the directory",  # text displayed before the help text
        epilog="Enjoy the program",  # text shown after the help text
        prefix_chars='/',  # by default, std. prefix char is the dash (-)
        # add_help=False  # disables the help (by default, it is true)
        )

# add the arguments
my_parser.add_argument('Path',
        metavar='path',
        type=str,
        help='the path to list')
# optional argument (generally, starts with - or --)
my_parser.add_argument('/l',
        '//long',
        action='store_true',
        help='enable long listing format'
        )

# execute the parse_args() method
args = my_parser.parse_args() # get a Namespace object that contains the user input

input_path = args.Path

if not os.path.isdir(input_path):
    print("The path specified doesn't exist")
    sys.exit()

for line in os.listdir(input_path):
    if args.long:
        size = os.stat(os.path.join(input_path, line)).st_size
        line = "%10d  %s" % (size, line)
    print(line)
