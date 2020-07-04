#!/usr/bin/env python

def func(x=3, text='2'):
    print(x)
    if text == '5':
        print('Text is ', text)
    else:
        print(text)


func(text='5')  # given default value for x so no need here
