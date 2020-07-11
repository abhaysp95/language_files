#!/usr/bin/env python3

# we can use 'else' if the code block inside 'try' ran without any erros

def first_example():
    try:
        num = int(input('Enter a number: '))
        assert num % 2 == 0
    except:
        print("Not an even number!")
    else:
        print(1/num)


# the above one could be done like this also
def second_example():
    num = int(input('Enter a number: '))
    assert num % 2 == 0, "Not an even number"
    reciprocal = 1/num
    print(reciprocal)


# finally
def third_example():
    try:
        fopen = open("foo.txt", encoding='UTF-8')
        # do some operation
    finally:
        fopen.close()


second_example()
