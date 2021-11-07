import argparse

my_parser = argparse.ArgumentParser()
my_parser.add_argument(
        '--input', action='store', type=int, nargs=3,
        choices=[42, 84, 63]  # domain of allowed values
        )
my_parser.add_argument('-s',
        '--string',
        action='store',
        nargs='?',
        # type=int, # by default, all the input argument values are treated as if they were strings
        default="my default string",
        required=True  # if you want to force user to specify the value for an optional argument
        )

args = my_parser.parse_args()

print(args.input)  # value of 'dest'

# the nargs keyword can have following:
# By default, one argument will be consumed and a single value will be
# produced. Other values are:
# - N (an int): consumes N arguments (and produces a list)
# - '?' consumes zero or one arguments
# - '*' consumes zero or more arguments (and produces a list)
# - '+' consumes one or more arguments (and produces a list)
# - argparse.REMAINDER: all the values that are remaining in the command line

# the difference between default and nargs=1 is that, with default a
# single value will be produced, but with nargs=1 a list containing
# single value will be produced

print(args.string)
