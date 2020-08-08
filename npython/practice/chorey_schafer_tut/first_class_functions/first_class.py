#!/usr/bin/env python3

# lets see a semi-practical example

def html_tag(tag):

    def wrap_text(msg):
        return "<{0}>{1}</{0}>".format(tag, msg)

    return wrap_text

print_h1 = html_tag('h1')  # at this point wrap_text isn't executed
print(print_h1('Test Headline'))
print(print_h1('Test Another headline'))

print_p1 = html_tag('p1')
print(print_p1("This is a paragraph."))













# def logger(msg):

    # def log_msg():
        # print("Log: ", msg)

    # return log_msg

# now log_hi is a function as it got a function from logger
# log_hi = logger("Hello, this is logger function")
# log_hi()


































# like map function is a high order function

# def square(x):
    # return x * x

# def cube(x):
    # return x * x * x

# def my_map(func, arg_list):
    # result = []
    # for item in arg_list:
        # result.append(func(item))
    # return result

# cubes = my_map(cube, [1, 2, 3, 4, 5])

# print(cubes)















# def square(x):
    # return x * x
# f = square(5)
# f = square  # not execute, just set the variable to the function

# print(square)
# print(f)
# print(f(5))


# if function takes another function as argument or returns another function, that's when it's called higher order function
