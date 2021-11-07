import argparse

my_parser = argparse.ArgumentParser(fromfile_prefix_chars='@')

my_parser.add_argument('a',
        help='a first argument')

my_parser.add_argument('b',
        help='a second argument')
my_parser.add_argument('c',
        help='a third argument')
my_parser.add_argument('d',
        help='a fourth argument')
my_parser.add_argument('e',
        help='a fifth argument')

my_parser.add_argument('-v',
        '--verbose',
        action='store_true',
        help='an optional argument')

args = my_parser.parse_args()

print("You have provided all the perimeters")
