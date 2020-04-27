#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-23
Description: task completion, basic of function
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-23
"""


# function for blueprints <<<
def blueprint_models(get_blueprints, get_completed_models):
    '''Stimulate printing each design, until none are left.
    Move each design to complete models after printing'''

    while get_blueprints:
        current_design = get_blueprints.pop()
        print(f"printing model: {current_design}")
        get_completed_models.append(current_design)
# >>>


# function to show complete models <<<
def show_completed_models(completed_models):
    '''show all the models that are processed'''
    for models in completed_models:
        print(models)
# >>>


# main function <<<
def main():
    '''Entering in main function'''
    blueprints = []
    completed_models = []
    prompt = '> '

    # taking value from user
    print('Enter the items for blueprints(uncompleted models):', end='\n')
    print('Press "q" to cancel entry')
    while True:
        value = input(prompt)
        if value == 'q':
            break
        blueprints.append(value)

    print('Are there any completed models?\n'
          'Enter "yes/no"', end='\n')
    value = input(prompt)
    if value != 'no':
        print('Enter the completed items'
              'press "q" to quit', end='\n')
        while True:
            value = input(prompt)
            if value == 'q':
                break
            completed_models.append(value)

    # calling other functions
    blueprint_models(blueprints, completed_models)
    show_completed_models(completed_models)
# >>>


if __name__ == "__main__":
    main()
