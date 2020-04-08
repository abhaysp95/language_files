#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-07
Description: using argv and input in combination
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-07
"""

# using argv and input

from sys import argv


def main():
    '''entering in main function'''
    script, user_name, path = argv  # pylint: disable=W0632
    prompt = '> '

    print(f"""Hi, {user_name}, I'm the {script} script
    from {path}.
    """)
    print("I'd like to ask you a few questions.")
    print(f"Do you like me {user_name}?")
    likes = input(prompt)

    print(f"Where do you live {user_name}?")
    lives = input(prompt)

    print(f"What kind of computer do you have?")
    computer = input(prompt)

    print(f'''
    Alright, so you said '{likes}' about liking me.
    You live in {lives}. Not sure where that is.
    And you have a {computer} computer. Nice.
    ''')


if __name__ == '__main__':
    print(main.__doc__)
    main()
