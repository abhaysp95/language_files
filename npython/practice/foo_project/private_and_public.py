#!/usr/bin/env python


# python doesn't stops you from using private out of scope of other file, it's
# just a naming convention that you shouldn't do it

class _Private:
    # everything within this class is private
    name_is = 'Private'
    '''this is a private class'''
    def __init__(self, name):
        self.name = name


class NotPrivate:
    '''this is not a private class'''
    def __init__(self, name):
        self.name = name
        self.priv = _Private(name)
        self.privname = _Private.name_is

    # private method
    def _display(self):
        print('Hi')

    # not private method
    def display(self):
        print('Hi')


if __name__ == "__main__":
    new_name = NotPrivate('Dean')
    print(new_name.name)
    print(new_name.priv.name)
