#!/usr/bin/env python3

# in python2 raw_input() takes input as string
# and input() takes as python expression
# but in python3 input() treates expression just like string

print('Enter something like {}'.format('123 + 1'))
my_number = input('Enter number: ')
print('By just input(): ' + my_number)

# evaluate the entered string(expression)
print("After Evaluation: {}".format(eval(my_number)))
