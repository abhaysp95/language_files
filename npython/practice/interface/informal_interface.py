#!/usr/bin/env python3


# An informal interface is a class that defines methods that can be overridden, but there's no strict enforcement
class InformalParserInterface:
    def load_data_source(self, path: str, file_name: str) -> str:
        '''load in the file for extracting text'''
        pass

    def extract_text(self, full_file_name: str) -> dict:
        '''extract text from the currently loaded file'''
        pass


# to use your interface you must create a concrete class. It's a subclass of the interface that provides an implementation of the interface's methods.
class PdfParser(InformalParserInterface):
    '''Extract text from pdf'''
    def load_data_source(self, path: str, file_name: str) -> str:
        '''overrides InformalParserInterface.load_data_source()'''
        pass

    def extract_text(self, full_file_name: str) -> dict:
        '''overrides InformalParserInterface.extract_text()'''
        pass

class EmlParser(InformalParserInterface):
    '''extract text from an email'''
    def load_data_source(self, path: str, file_name: str) -> str:
        '''overrides InformalParserInterface.load_data_source()'''
        pass
    def extract_text_from_email(self, full_file_path: str) -> dict:
        '''doesn't overrides InformalParserInterface.extract_text()'''
        pass


print(issubclass(PdfParser, InformalParserInterface))  # True
print(issubclass(EmlParser, InformalParserInterface))  # True

# this is a problem, since EmlParser is violating the defination of interface

# check MRO:
# MRO(Method Resolution Order) tells you the superclasses of the class in question, as well as the order in which they’re searched for executing a method. You can view a class’s MRO by using the dunder method cls.__mro__:
print(PdfParser.__mro__)
print(EmlParser.__mro__)
