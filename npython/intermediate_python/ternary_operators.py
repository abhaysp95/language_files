# More commonly known as conditional expressions in python. These operators evaluate something based on a condition being 'true' or 'not'
is_nice = True
state = "nice" if is_nice else "not nice"
print("state:", state)

# It allows to quickly test a condition instead of a multiline if statement. Often times it can be immensely helpful and can make your code compact but still maintainable
# Another more obscure and not widely used example involves tuples
# blueprint: (if_test_is_false, if_test_is_true)[test]
personality = ("mean", "nice")[is_nice]
print("personality:", personality)

# This works simply because True == 1 and False == 0 and so can be done with lists in addition to tuples
# Apart from being little confusing and not generally liked by Pythonists for not being pythonic, tupled ternary is avoided because it results in both elements of the tuple being evaluated, whereas the if-else ternary operator does not
condition = True
print(2 if condition else 1 / 0)
# print((1/0, 2)[condition])  # results in ZeroDivisionError

# Shorthand ternary
print(True or "some")
print(False or "some")
# this is helpful in case if you quickly want to check for the output of a function and give a useful message if the output is empty

def my_function(real_name, optional_display_name=None):
    optional_display_name = optional_display_name or real_name
    print(optional_display_name)
my_function("John")
my_function("Mike", "anonymous")
