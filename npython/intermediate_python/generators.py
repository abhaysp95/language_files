import pathlib
import itertools

# there are 3 parts for iteration:
# 1. Iterable
# 2. Iterator
# 3. Iteration

# 1. Iterable: any object in python which has an __iter__ or a __getitem__
#    method defined which returns an 'iterator' or can take indexes(used by
        #    __getitem__). In short an iterable is any object which can provide
#    us with an 'iterator'.
# Note: __getitem__ is legacy before python has modern iterator(__item__). Look
# here: https://stackoverflow.com/a/20551346

# 2. Iterator: object in python which has a 'next'(python2) or __next__ method
#    defined. Iterators are iterables too(but I think vice-versa is not possible)

# 3. Iteration: It is the process of taking an item from something e.g., a
#    list. When we use a loop to loop over something it is called iteration

# Generators
# Generators are iterators, but you can only iterate over them once. It's
# because they do not store all the values in memory, they generate the values
# on the fly. You use them by iterating over them, either with a 'for' loop or
# by passing them to any function or construct that iterates. Most of the time
# generators are implemented as functions. However, they do not return a value,
# they yield it.

def generator_function():
    for i in range(3):  # put some big value here
        yield i

for item in generator_function():
    print(item)

# Generators are best for calculating large sets of results(particularly
        # calculations involving loops themselves) where you don't want to
# allocate the memory for all results at the same time

def fibon(n):
    a = b = 1
    for _ in range(n):
        yield a
        a, b = b, a + b

for x in fibon(100):
    print(x)

def facto(n):
    if n == 0: return 1
    a = 1
    for i in range(n + 1):
        yield a
        a = a * (i + 1)

for x in facto(10):
    print(x)


gen = generator_function()
print("1: ", next(gen))
print("2: ", next(gen))
print("3: ", next(gen))
# print("4: ", next(gen)) # StopIteration error


my_string = "your name"
# next(my_string)  # TypeError: 'str' object is not an iterator
# It's an iterable but not an iterator. That means it supports iteration but we
# can't iterate directly over it

int_var = 1779
# iter(int_var)  # int isn't iterable
my_iter = iter(my_string)  # now str is
print(next(my_iter))

for i in my_iter:
    print(i)
# print(next(my_iter))  # StopIteration Error(my_iter was generator)


class reverse_iter:
    def __init__(self, lst):
        self.lst = lst
        lst.reverse()
        self.i = 0
        self.lstlen = len(lst)

    # makes object iterable
    def __iter__(self):
        return self

    # makes iterator
    def __next__(self):
        if self.i < self.lstlen:
            i = self.i
            self.i += 1
            return self.lst[i]
        else:
            raise StopIteration()

    def pt(self):
        print(self.lst)

it = reverse_iter([1, 2, 3])
it.pt()
# print(next(it))
# print(next(it))
# print(next(it))
# print(next(it))
for i in it:
    print(i)  # we don't have __iter__ in 'it' object, that's why this iterable


# how generator works internally
# when a generator is clalled, it returns a generator object without even beginning execution of the function. When 'next' method is called for the first time, the function starts executing until it reaches 'yield' statement. The yielded value is returned by the 'next' call.
# demonstration that interplays between 'yield' and call to '__next__' method on generator object
def foo():
    print("begin")
    for i in range(3):
        print("before yield", i)
        yield i
        print("after yield", i)
    print("end")

# for x, i in enumerate(foo()):
    # print("==> ", x + 1)
    # print(i)
f = foo()
print(next(f))
print(next(f))
print(next(f))
# print(next(f))  # end will be printed with StopIteration Error

def integers():
    "infinite sequence of integers"
    i = 1;
    while True:
        yield i
        i = i + 1

def squares():
    for i in integers():
        yield i * i

def take(n, seq):
    seq = iter(seq)
    result = list()
    try:
        for _ in range(n):
            result.append(next(seq))
    except StopIteration:
        pass
    return result
print(take(5, squares()))

# for more details: https://anandology.com/python-practice-book/iterators.html

## Problem 2
# Write a program that takes one or more filenames as arguments and prints all the lines which are longer than 40 characters
print("\nproblem2:\n")
def readfiles(filenames):
    for file in filenames:
        try:
            with open(file, mode='r') as fid:
                for line in fid:
                    yield line
        except FileNotFoundError:
            pass

def content_more_than_40(lines):
    return (line for line in lines if len(line) > 40)

def print_lines(lines):
    for line in lines:
        print(line, end="")

def problem2():
    filenames = [ "args_and_kwargs.py", "debugging.py", "generators.py" ]
    lines = readfiles(filenames)
    lines = content_more_than_40(lines)
    print_lines(lines)

problem2()


## problem 3
# Write a function 'findfiles' that recursively descends the directory tree for the specified directory and generates paths for all the files in the tree
print("\nproblem3:\n")
def findfiles(path, level=0):
    try:
        if path.is_file():
            yield ('=' * level + '>' + str(path))
            return
    except FileNotFoundError:
        return
    for p in path.iterdir():
        try:
            depth = len(p.relative_to(path).parts) + level
            yield from findfiles(p, depth)
        except NotADirectoryError:
            pass
all_files = findfiles(pathlib.Path.home().joinpath("Music"))
print("type:", type(all_files))
for file in all_files:
    print(file)


## problem 7
# Write a function 'split_file', that takes an integer 'n' and a filename and splits the file into multiple small files with each having 'n' lines
print("\nproblem7:\n")
def getlines(filename):
    try:
        with filename.open(mode='r') as fid:
            yield from fid
    except FileNotFoundError:
        pass

def get_unique_path(dir, pattern):
    counter = 0
    while True:
        counter += 1
        path = dir / pattern.format(counter)
        if not path.exists():
            return path

def operate_n_lines(lines, file, n):
    try:
        count = 0
        # file.write_text("".join(((line) for c, line in enumerate(lines) if c < n)))
        with open(file, mode="w") as fid:
            for line in lines:
                if count >= n:
                    return
                fid.writelines(line)
                count += 1
    except FileNotFoundError as FE:
        print(FE.strerror)

def peek(iterable):
    try:
        top = next(iterable)
    except StopIteration:
        return None
    return top, itertools.chain([top], iterable)

def split_file(filename, n = 1):
    lines = getlines(filename)
    pattern =  "sp_file{:03d}.txt"
    while True:
        res = peek(lines)
        if res is None:
            break
        _, lines = res
        file = get_unique_path(filename.parent, pattern)
        operate_n_lines(lines, file, n)

n = 10
filename = pathlib.Path.cwd() / "generators.py"
split_file(filename, n)
