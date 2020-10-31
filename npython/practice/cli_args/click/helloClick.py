#!/usr/bin/env python3

import click

@click.command()
@click.option('--count', default=1, help='Number of greetings')
@click.option('--name', prompt='Your name', help='The person to greet')
def hello(count, name):
    '''simple program that greets name for total given count'''
    for x in range(count):
        click.echo('Hello {}!'.format(name))

# not working
@click.option('--addr', prompt='Your address', help='address of person')
def printaddr(addr):
    click.echo('This is address: {}'.format(addr))

if __name__ == "__main__":
    hello()
    # printaddr()
