import pathlib
import collections
from datetime import datetime

# there are classmethods like .cwd() and .home()

print("cwd:", pathlib.Path.cwd())
print("home:", pathlib.Path.home())

# A path can be explicitly created from its string representation
print("custom path:",
        pathlib.Path(r'C:\this\is\linux\file.txt'))
# we use raw string because '\' could be considered for escape characters

# Another way to construct a path is to join the parts of the path using the
# special operator '/'. The forward slash operator is used independently of the
# actual path seperator on the platform
print("custom path:",
        pathlib.Path.home() / 'this' / 'is' /
        'linux' / 'file.txt')

# the '/' can join several paths or mix of paths and strings(as above) as long
# as there is atleast one Path object. If you don't like '/' notation, you can
# do same thing with '.joinpath()' method
print("custom path:",
        pathlib.Path.home().joinpath(
            'this', 'is', 'linux', 'file.txt'))


# Reading and writing files

# traditionally, the way to 'read and write file in python' has been to use the
# built-in 'open()' function. This is still true as the 'open()' function can
# use 'Path' objects directly. The following example finds all headers in a
# markdown file and prints them
path = pathlib.Path.cwd() / 'test.md'
try:
    with open(path, mode='r') as fid:
        headers = [line.strip() for line in fid if line.startswith('#')]
    print('\n'.join(headers))
except FileNotFoundError:
    print("File \"%s\" doesn't exist" % path)

# An equivalent alternative is to call '.open()' on the path object
try:
    with path.open(mode='r') as fid:
        headers = [line.strip() for line in fid if line.startswith('#')]
    print('\n'.join(headers))
except FileNotFoundError:
    print("File \"%s\" doesn't exist" % path)

# In fact, 'Path.open()' is calling the built-in 'open()' behind the scenes.
# Which option you use is mainly a matter of taste
# For simple reading and writing of files, there are couple of convenience
# methods in 'pathlib' library:
# '.read_text()': open the path in text mode and return the contents as a
# string
# '.read_bytes()': open the path in binary/bytes mode and return the contents
# as a bytestring
# '.write_text()': open the path and write string data to it
# '.write_bytes()': open the path in binary/bytes mode and write data to it

# Each of these methods handles the opening and closing of the file, making
# them trivial to use
print("content of '%s':" % path)
print(path.read_text())

# The '.resolve()' method will find the full path. Below, we confirm that the
# current working directory is used for simple file names
path = pathlib.Path('test.md')
print("current path:", path)
print("path.resolve():", path.resolve())
print("path.parent:", path.parent)
print("path.resolve().parent", path.resolve().parent)
print("pathlib.Path.cwd():", pathlib.Path.cwd())
print("path.resolve().parent == pathlib.Path.cwd():",
        path.resolve().parent == pathlib.Path.cwd())
print("path.parent == pathlib.Path.cwd():",
        path.parent == pathlib.Path.cwd())
# Note that when paths are compared, it is their representations that are
# compared. In the example above, 'path.parent' is not equal to
# 'pathlib.Path.cwd()' because path.parent is represented by '.' while
# pathlib.Path.cwd() is represented by '/home/username/folders/.'


# Picking out components of Path

# the different parts of a path are conviniently available as properties. Basic examples include:
# '.name': the filename without any directory
# '.parent': the directory containng the file, or the parent directory if path is a directory
# '.stem': the filename without the suffix
# '.suffix': the file extension
# '.anchor': the part of the path before the directories
path = pathlib.Path.cwd().joinpath('test.md')
print("path:", path)
print("path.name:", path.name)
print("path.parent:", path.parent)
print("path.stem:", path.stem)
print("path.suffix:", path.suffix)
print("path.anchor:", path.anchor)
# '.parent' returns new Path object, whereas the other properties return
# string(so know that not every properties or methods have same return type).
# This means for instance that '.parent' can be chained as in the last example
# or even combined with / to create completely new paths
print(path.parent.parent / ('new' + path.suffix))


# Moving or deleting files

# To move a file, use '.replace()'. Note that if the destination already
# exists, '.replace()' will overwrite it. Unfortunately, 'pathlib' doesn't
# explicitly support safe moving of files. To avoid possibly overwriting the
# destination path, the simplest is to test whether the destination exists
# before replacing
new_path = (path.parent / ('new' + path.suffix))
if not new_path.exists():
    path.replace(new_path)
# above snippet renames(moves) already existing file('test.md') to 'new.md'.
# Note that, 'new.md' is not existing there

# However, this does leave the door open for possible race condition. Another
# process may add a file at the destination path between the execution of the
# if statement and '.replace()' method. If that is a concern, a safer way is to
# open the destination path for 'exclusive creation' and explicitly copy the
# source data
try:
    with new_path.open(mode='xb') as fid:
        fid.write(path.read_bytes())
except FileExistsError:
    print("destination '%s' already exists" % new_path)
# this code above does copy. To perform a move, simply delete source after the
# copy is done. Make sure no exception was raised though
# directories and files can be deleted using '.rmdir()' and '.unlink()'
# respectively

# when renaming files, useful methods might be '.with_name()' and
# '.with_suffix()'. They both return the original path but with the name or the
# suffix replaced.
print("new_path:", new_path)
print("new_path.with_suffix('.py')",
        new_path.with_suffix('.py'))
# just puts the name
print("new_path.with_name('temporary')",
        new_path.with_name('temporary'))
# puts the name with existing file extension
print("new_path.with_stem('tempo')",
        new_path.with_stem("tempo"))



# Examples:

# Counting files

# There are few different ways to list many files. The simplest is the
# '.iterdir()' method, which iterates over all files in the given directory.
# The following example combines '.iterdir()' with the 'collections.Counter'
# classs to count how many files there are of each filetype in the current
# directory
print("file count:",
        collections.Counter(p.suffix for p in pathlib.Path.cwd().iterdir()))

# More flexible file listings can be created with the methods '.glob()' and
# '.rglob()'(recursive glob). For instance, 'pathlib.Path.cwd().glob("*.txt")'
# returns all files with a ".txt" suffix in the current directory. The
# following only counts filetypes starting with 'p'
print("file counts starting with 'p':",
        collections.Counter(p.suffix for p in pathlib.Path.cwd().glob("*.p*")))

# Display a directory tree

def tree(directory):
    print(f'+ {directory}')
    for path in sorted(directory.rglob('*')):
        depth = len(path.relative_to(directory).parts)
        spacer = '    ' * depth
        print(f'{spacer}+ {path.name}')

# tree(pathlib.Path.home().joinpath("Music"))
# we need to know how far away from the root directory a file is located. To do
# this, we first use '.relative_to()' to represent a path relative to the root
# directory. Then, we count the number of directories(using the '.parts'
# property) in the representation.

# Find the last modified file

time, file_path = max((f.stat().st_mtime, f) for f in path.parent.iterdir())
print(datetime.fromtimestamp(time), file_path)
# you can even get contents of the file that was last modified with a similar
# expression
print(max((f.stat().st_mtime, f) for f in path.parent.iterdir())[1].read_text())
# The timestamp returned from the different '.stat().st_properties' represents
# seconds since UNIX Epoch time(Jan 1, 1970). In addition to
# datetime.fromtimestamp, time.localtime or time.ctime may be used to convert
# the timestamp to something more usable

# Create a unique file name
def unique_path(directory, name_pattern):
    counter = 0
    while True:
        counter += 1
        path = directory / name_pattern.format(counter)
        if not path.exists():
            return path

path = unique_path(pathlib.Path.cwd(), 'test{:03d}.txt')
print(path)
