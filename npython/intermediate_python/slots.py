# In python, every class can have instance attributes. By default Pyuthon uses a dict to store an dobject's instance attributes. This is really helpful as it allows setting arbitrary new attributes at runtime
# However, for small classes with known attributes it might be a bottleneck. The dict wastes a lot of RAM. Python can't just allocate a static amount of memory at object creation to store all the attributes. Therefore it sucks a lot of RAM if you create a lot of objects(like in thousands and millions). Still there is a way to circumvent this issue. It involves the usage of __slots__ to tell Python not use a dict, and only allocate space for fixed set of attributes. Here is an example with and without __slots__:

# without __slots__:
class MyClass():
    def __init__(self, name, identifier):
        self.name = name
        self.identifier = identifier
        self.set_up()

    def set_up(self):
        pass

# With __slots__:
class MyClass2():
    __slots__ = ['name', 'identifier']
    def __init__(self, name, identifier):
        self.name = name
        self.identifier = identifier
        self.set_up()

    def set_up(self):
        pass
