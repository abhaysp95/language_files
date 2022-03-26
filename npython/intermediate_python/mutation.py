# mutable = "able to be changed"
# immuatable = "constant"

foo = ['hi']
print(foo)

bar = foo
bar += ['bye']
print("foo:", foo)
print("bar:", bar)

# It's mutability in action. Whenever you assign a variable to another variable
# of mutable datatype, any changes to the data are reflected by both variables.
# The new variable is just an alias for the old variable. This is only true for
# mutable datatypes. Here is gotcha involving functions and mutable data types:
def add_to(num, target=[]):
    target.append(num)
    return target

print("first call:", add_to(1))   # [1]
print("second call:", add_to(2))  # [1, 2]
print("third call:", add_to(3))   # [1, 2, 3]
# you might be expecting that a fresh list would be created when you call
# add_to(x)
# Well again, it is mutability of lists which causes this pain. In python, the
# default arguments are evaluated once when the function is defined, not each
# time the function is called. You should never define default arguments of
# mutable type(exception exists, ofcourse), instead do something like this
def add_to2(element, target=None):
    if target is None:
        target = []
    target.append(element)
    return target
print("first call:", add_to2(11))   # [11]
print("second call:", add_to2(12))  # [12]
print("third call:", add_to2(13))   # [13]
