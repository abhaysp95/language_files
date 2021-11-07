import argparse

my_parser = argparse.ArgumentParser()
my_parser.add_argument('-v',
        '--verbosity',
        action='store',
        type=int,
        metavar='LEVEL')

args = my_parser.parse_args()
print(vars(args))

# If an argument accepts an input value, it can be useful to give this
# value a name that the parser can use to generate the help message,
# and this can be done by using the metavar keyword.
