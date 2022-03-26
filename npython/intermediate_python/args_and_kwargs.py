# *args is used to send a 'non-keyworded' variable length argument list to the function

def test_var_args(f_arg, *argv):
    print("first normal arg:", f_arg)
    for arg in argv:
        print("another arg through *argv:", arg)

test_var_args("why", "now", "then", "in", "this", "there")

# **kwargs allows you to pass 'keyworded' variable length of arguments to a function
# use **kwargs if you want to handle 'named arguments' in a function

def greet_me(**kwargs):
    for key, value in kwargs.items():
        print("{0} = {1}".format(key, value))

greet_me(name="myself", work="something")

# using *args and **kwargs to call a function

def test_args_kwargs(arg1, arg2, arg3):
    print("arg1:", arg1)
    print("arg2:", arg2)
    print("arg3:", arg3)

args = ("two", 3, 5)
test_args_kwargs(*args)
kwargs = {"arg3": 3, "arg2": "two", "arg1": 5}
test_args_kwargs(**kwargs)

# order of using *args and **kwargs and formal args
# some_func(fargs, *args, **kwargs)
