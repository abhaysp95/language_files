#!/usr/bin/env python


import private_and_public


def main():
    '''inside main function'''
    name_is = private_and_public.NotPrivate('Bobby')
    print(name_is.name)
    # private_and_public.NotPrivate._display('Jake')


if __name__ == "__main__":
    main()
