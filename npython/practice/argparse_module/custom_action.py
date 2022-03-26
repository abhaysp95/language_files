import argparse

class VerboseStore(argparse.Action):
    def __init__(self, option_strings, dest, nargs=None, **kwargs):
        print(option_strings)
        print(dest)
        print(nargs)
        print(kwargs)
        if nargs is not None:
            raise ValueError('nargs not allowed')
        super(VerboseStore, self).__init__(option_strings, dest, **kwargs)

    def __call__(self, parser, namespace, values, option_string=None):
        # print(parser)
        # print(namespace)
        print("Here I'm setting the "\
                "values %r for the %r option..." % (values, option_string))
        setattr(namespace, self.dest, values)

my_parser = argparse.ArgumentParser()
my_parser.add_argument('-i', '--input', action=VerboseStore, type=int)

args = my_parser.parse_args()

print(vars(args))
