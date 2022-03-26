import argparse

# as already seen, when you add an argument to the parser, the value
# of this argument is stored in a property of the Namespace object.
# This property is named by default as the first argument passed to
# '.add_argument()' for the positional argument and as the long option
# string for optional arguments.

# if an option used dashes (-, as is fairly common), they will be
# converted to underscores in the property name

my_parser = argparse.ArgumentParser()
my_parser.add_argument('-v'
        '--verbosity-level',
        action='store',
        type=int)

# however, it's possible to specify the name of this property just by
# using the keyword 'dest' when you're adding an argument to the
# parser

my_parser.add_argument('-i',
        '--info',
        type=int,
        dest='program_information_level')

args = my_parser.parse_args()
print(vars(args))
print(args.v__verbosity_level)
print(args.program_information_level)
