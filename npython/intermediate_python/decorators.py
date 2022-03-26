# Decorators are a significant part of Python. In simple words: they are
# functions which modify the functionality of other functions. They help to
# make our code shorter and more pythonic
# Let's discuss how to write our own decorator

## Everything in Python is an object
def hi(name="myname"):
    return "hi " + name

print(hi())

# we can assign function to a variable like
greet = hi
print(greet())

# let's see what happens if we delete the old hi function
del hi
# print(hi())  # NameError
print(greet())  # still works

## Defining functions within functions
# In python, we can define functions inside other functions
def hi(name="your_name"):
    print("now you are inside the hi() function:", name)

    def greet():
        return "now you are inside the greet() function"

    def welcome():
        return "now you are inside the welcome() function"

    print(greet())
    print(welcome())
    print("now you are back in the hi() function")
hi()

# This shows that whenever we call hi(), greet() and welcome() are also called.
# However, the greet() and welcome() functions are available outside the hi()
# function

## Returning functions from within functions
# It is not necessary to execute one function within another function. We can
# return it as an output as well
def hi_again(name="your_name"):
    def greet():
        return "now you are in the greet() function"

    def welcome():
        return "now you are in the welcome() function"

    return greet if name == "your_name" else welcome

a = hi_again()
print(a)
# this shows that a now points at greet function
print(a())

## Giving a function as an argument to another function
def hi_third_time():
    return "hello, idiot"

def do_something_before_hi(func):
    print("This is just an idiotic message before executing hi() third time")
    print(func())

do_something_before_hi(hi_third_time)

## Writing our first decorator
def a_new_decorator(a_func):
    def wrap_the_function(*args, **kwargs):
        print("I'm doing some boring work before executing  a_func()")
        a_func(*args, **kwargs)
        print("I'm doing some boring work after executing  a_func()")
    return wrap_the_function

def a_function_requiring_decorator():
    print("I'm the function which needs some decoration to remove my foul smell")

a_function_requiring_decorator()
a_function_requiring_decoration = a_new_decorator(a_function_requiring_decorator)
a_function_requiring_decoration()
# we just applied the previously learned principles. This is exactly what the
# decorators do in Python. They wrap a function and modify its behaviour in one
# way or another. Using @ is just a short way of making up a decorated function
@a_new_decorator
def a_function_needing_attention():
    """I need decorator"""
    print("I'll do anything to seek attention")
a_function_needing_attention()

# there is one problem though
print(a_function_needing_attention.__name__)
# The output is not we expected. It's name is "a_function_needing_attention".
# Well, our function was replaced by 'wrap_the_function'. It overrode the name
# and docstring of our function. Luckily, Python provides us a simple function
# to solve this problem and that is 'functools.wraps'
from functools import wraps

def another_new_decorator(func):
    @wraps(func)
    def wrap_the_function():
        print("again doing boring work before")
        func()
        print("again doing boring work after")
    return wrap_the_function

@another_new_decorator
def needy_function():
    print("I need decorator")
needy_function()
print(needy_function.__name__)

## Blueprint

def decorator_name(func):
    @wraps(func)
    def decorated(*args, **kwargs):
        if not can_run:
            return "Function will not run"
        return func(*args, **kwargs)
    return decorated

@decorator_name
def func():
    return("Function is running")

can_run = True
print(func())
can_run = False
print(func())
# Note: @wraps takes a function to be decorated and adds the functionality of
# copying over the function name, docstring, arguments list etc. This allows us
# to access the pre-decorated function's properties in the decorator

## Use-Cases
# Now let's take a look at the areas where decorators really shine and their
# usage makes something really easy to manage

# Authorization
# Decorators can help to check whether someone is authorized to use an endpoint
# in a web application. They are extensively used in Flask web framework and
# Django. Here is an example to employ decorator based authentication:

# def requires_auth(f):
    # @wraps(f)
    # def decorated(*args, **kwargs):
        # auth = request.authorization
        # if not auth or not check_auth(auth.username, auth.password):
            # authenticate()
        # return f(*args, **kwargs)
    # return decorated

# Logging
# Logging is another area where the decorators shine
def logit(func):
    @wraps(func)
    def with_logging(*args, **kwargs):
        print(func.__name__ + " was called")
        return func(*args, **kwargs)
    return with_logging


@logit
def addition_func(x):
    return x + x
print(addition_func(10))

## Decorators with Arguments
# Come to think of it, isn't @wraps also a decorator? But, it takes an argument
# like any normal function can do. So, why can't we do that too ?
# This is because when you use the @my_decorator syntax, you are applying a
# wrapper function with a single function as a parameter. Remember, everything
# in Python is an object, and this includes functions!

## Nesting a decorator within a function
# Let's go back to our logging example, and create a wrapper which lets us
# specify a logfile to output to
def logit2(logfile="out.log"):
    def logging_decorator(func):
        @wraps(func)
        def wrapped_function(*args, **kwargs):
            log_string = func.__name__ + " was called"
            print(log_string)
            with open(logfile, mode='a') as op_file:
                op_file.write(log_string + '\n')
            return func(*args, **kwargs)
        return wrapped_function
    return logging_decorator

@logit2()
def myfunc1():
    pass
myfunc1()

@logit2(logfile="func2.log")
def myfunc2(x, y):
    return x + y
print(myfunc2(10, 20))

## Decorator classes
# Now we have our logit decorator in production, but when some parts of our
# application are considered critical, failure might be something that needs
# more immediate attention. Let's say sometimes you want to just log to a file.
# Other times you want an email sent, so the problem is brougth to you
# rattention, and still keep a log for your own records. This is a case for
# using inheritence, but so far we've only seen functions being used to build
# decorators.
# Luckily, classes can also be used to build decorators. Sol, let's rebuild
# logit as a class instead of a function

class logit3():
    _logfile = "out.log"

    def __init__(self, func):
        self.func = func

    def __call__(self, *args):
        log_string = self.func.__name__ + " was called: " + str(*args)
        print(log_string)
        with open(self._logfile, mode="a") as op_file:
            op_file.write(log_string)
        self.notify()
        return self.func(*args)

    def notify(self):
        pass

# This implementation has and additional advantage of being much cleaner than
# the nested function approach, and wrapping a function still will use the same
# syntax as before
# logit3._logfile = "out2.log"
@logit3
def factorial(num):
    if num <= 1:
        return 1
    return num * factorial(num - 1)
print(factorial(10))

# Now, let's subclass logit3 to add email functionality(topic not covered in
# this file)

class email_logit(logit3):
    def __init__(self, email='admin@myproject.com', *args, **kwargs):
        self.email = email
        super(email_logit, self).__init__(*args, **kwargs)
        # super().__init__(*args, **kwargs)
        # super(email_logit, self).__init__(email_logit)

    def notify(self):
        # send an email to self.email
        # (not implemented)
        pass

@email_logit
def temp_func():
    pass
temp_func()



# How will you access the properties from top class inside of nested class
# class logit3():
    # def __init__(self, filename="out.log"):
        # self._logfile = filename

    # def __call__(self, func):
        # logfile = self._logfile

        # class logit_decorator():
            # def __init__(self, func):
                # self.func = func

            # def __call__(self, *args):
                # log_string = self.func.__name__ + " was called: " + str(*args)
                # print(log_string)
                # with open(logfile, mode="a") as op_file:
                    # op_file.write(log_string + '\n')
                # self.notify()
                # return self.func(*args)

            # def notify(self):
                # pass
        # return logit_decorator
