#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-06
Description: more printing techniques
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-06
"""


# main function <<<
def main():
    '''some techniques for print in python'''
    days = 'Mon Tue Wed Thu Fri Sat Sun'
    months = 'Jan\nFeb\nMar\nApr\nMay\nJun\nJul\nAug\nSep\nOct\nNov\nDec'

    print('Here are the days: ', days)
    print('Here are the months: ', months)
# >>>


print(main.__doc__)
main()
print("""
    There's something going on here.
    With three double-quotes.
    We'll be able to type as much as we like.
    Even 4 lines if we want, or 5, or 6.
""")
print('''
    Printing like this,
    also works in single quote.
    Count of these quotes should be three
    ofcourse, on both ends
''')
print("""
    If you want to put \" inside \" closed string,
    you have to use backslash (\\) to escape \",
    in order to print it like \", otherwise it'll throw error.
""")
print('''
    In same way to put \' inside \' closed string,
    use \\ to escape \'. Remember,
    you can use \' inside \" without escaping and
    \" inside \', it\'ll not give error.
''')
