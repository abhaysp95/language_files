def add(value1, value2):
    return value1 + value2

result = add(3, 5)
print(result)


# We could also have done this
def add2(val1, val2):
    global res
    res = val1 + val2

add2(3, 5)
print(res)

# In practical programming, you should try to stay away from global keyword as
# it only makes life difficult by introducing unwanted variables to the global
# scope

## Multiple return values
# So what if you want to return two variables from function instead of one?
# Among couple of approach, most famous is to use of global keyword. Let's take
# a look

def profile():
    global name
    global age
    name = "Danny"
    age = 30

profile()
print("name:", name)
print("age:", age)
# don't try to use the above mentioned method. some try to solve this problem
# by returning a list, tuple or dict with the required values after the
# function terminates. It is one way to do it and works like a charm
def profile2():
    name = "Danny"
    age = 30
    return name, age
profile_data = profile2()
print("name:", profile_data[0])
print("date:", profile_data[1])
# keep in mind that even in the example we are returning a tuple(despite the lack of parenthesis) and not seperate multiple values. If you want to take it one step further, you can also make use of 'namedtuple'
from collections import namedtuple
def profile3():
    Person = namedtuple('Person', 'name, age')
    return Person(name="Danny", age=31)
p = profile3()
print(p, type(p))
print("name:", p.name)
print("age:", p.age)
# or Use as plain tuple
print("name:", p[0])
print("age:", p[1])
# unpack it immediately
n, a = profile3()
print("name:", n)
print("age:", a)

# This is a better way to do it along with returning lists and dicts. Don't use
# 'global' keyword unless you know what you are doing. 'global' might be a
# better option in a few cases but is not in most of them
