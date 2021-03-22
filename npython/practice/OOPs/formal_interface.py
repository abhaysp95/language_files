#!/usr/bin/env python3

"""
reference: https://realpython.com/python-interface/#formal-interfaces
"""

# in order to make a formal interface, we'll need few more tools from abc module

# Using abc.ABCMeta

import abc

class FormalParserInterface(metaclass=abc.ABCMeta):
    @classmethod
    def __subclasshook__(cls, subclass):
        return (hasattr(subclass, 'load_data_source')
                and callable(subclass.load_data_source)
                and hasattr(subclass, 'extract_text')
                and callable(subclass.extract_text))

class PdfParser:
    """Extract text from a PDF"""
    def load_data_source(self, path: str, file_name: str) -> str:
        """Overrides FormalParserInterface.load_data_source()"""
        pass

    def extract_text(self, full_file_path: str) -> dict:
        """Overrides FormalParserInterface.extract_text()"""
        pass

class EmlParser:
    """Extract text from an email"""
    def load_data_source(self, path: str, file_name: str) -> str:
        """Overrides FormalParserInterface.load_data_source()"""
        pass

    def extract_text_from_email(self, full_file_path: str) -> dict:
        """A method defined only in EmlParser.
        Does not override FormalParserInterface.extract_text()"""
        pass

print(issubclass(PdfParser, FormalParserInterface))  # True
print(issubclass(EmlParser, FormalParserInterface))  # False


print("\n----------------------------------")
print("----------------------------------\n")

# using abc to Register a Virtual Subclass
# we can do this by .register() metamethod

class Double(metaclass=abc.ABCMeta):
    """Double precision floating point number"""
    pass

Double.register(float)

print(issubclass(float, Double))  # True
print(isinstance(1.2345, Double))  # True

# by .register() metamethod, Double is successfully registered as virtual subclass(probably base class) of flat

# after registering Double, you can use it as class decorator to set the decorated class as a virtual subclass
@Double.register
class Double64:
    """A 64-bit double-precision floating-point-number"""
    pass

print(issubclass(Double64, Double))  # True


print("\n----------------------------------")
print("----------------------------------\n")

# Using subclass Detection with registration

# .__subclasshook__() takes precedence over virtual subclass registration.
# To ensure that the registered virtual subclasses are taken into consideration,
# you must add NotImplemented to the .__subclasshook__() dunder method

# Updated FormalParserInterface

class UpdatedFormalParserInterface(metaclass=abc.ABCMeta):
    @classmethod
    def __subclasshook__(cls, subclass):
        return (hasattr(subclass, 'load_data_source')
                and callable(subclass.load_data_source)
                and hasattr(subclass, 'extract_text')
                and callable(subclass.extract_text)
                or NotImplemented)

class UpdatedPdfParser:
    """Extract text from a PDF"""
    def load_data_source(self, path: str, file_name: str) -> str:
        """Overrides FormalParserInterface.load_data_source()"""
        pass

    def extract_text(self, full_file_path: str) -> dict:
        """Overrides FormalParserInterface.extract_text()"""
        pass

@UpdatedFormalParserInterface.register
class UpdatedEmlParser:
    """Extract text from an email"""
    def load_data_source(self, path: str, file_name: str) -> str:
        """Overrides FormalParserInterface.load_data_source()"""
        pass

    def extract_text_from_email(self, full_file_path: str) -> dict:
        """A method defined only in EmlParser.
        Does not override FormalParserInterface.extract_text()"""
        pass

print(issubclass(UpdatedPdfParser, UpdatedFormalParserInterface))  # True
print(issubclass(UpdatedEmlParser, UpdatedFormalParserInterface))  # True
# due to registration, UpdatedEmlParser is considered virtual subclass of UpdatedFormalParserInterface,
# this is not we want since UpdatedEmlParser doesn't override .extract_text()


print("\n----------------------------------")
print("----------------------------------\n")

# Using abstract method declaration

class FormalParserInterfaceNew(metaclass=abc.ABCMeta):
    @classmethod
    def __subclasshook__(cls, subclass):
        return (hasattr(subclass, 'load_data_source')
                and callable(subclass.load_data_source)
                and hasattr(subclass, 'extract_text')
                and callable(subclass.extract_text)
                or NotImplemented)

    @abc.abstractmethod
    def load_data_source(self, path: str, file_name: str) -> str:
        """Load in the data set"""
        raise NotImplementedError

    @abc.abstractmethod
    def extract_text(self, full_file_path: str) -> dict:
        """Extract text from data set"""
        raise NotImplementedError

class PdfParserNew(FormalParserInterfaceNew):
    """Extract text from a PDF"""
    def load_data_source(self, path: str, file_name: str) -> str:
        """Overrides FormalParserInterface.load_data_source()"""
        pass

    def extract_text(self, full_file_path: str) -> dict:
        """Overrides FormalParserInterface.extract_text()"""
        pass

class EmlParserNew(FormalParserInterfaceNew):
    """Extract text from an email"""
    def load_data_source(self, path: str, file_name: str) -> str:
        """Overrides FormalParserInterface.load_data_source()"""
        pass

    def extract_text_from_email(self, full_file_path: str) -> dict:
        """A method defined only in EmlParser.
        Does not override FormalParserInterface.extract_text()"""
        pass

pdf_parser = PdfParserNew()
# eml_parser = EmlParserNew()
# with traceback message for eml_parser, you can know that you haven't overridden abstract methods.
# This is the behavior you expect when building a formal python interface
