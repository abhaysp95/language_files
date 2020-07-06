#!/usr/bin/env python

import re


log = "July 31 07:41:21 mycomputer bad_process[12345]: ERROR Performing package upgrade"

def index_method():
    index = log.index('[')
    print(log[index + 1 : index + 6])


def first_regex():
    # giving r"" means we are passing raw string to function
    regex = r"\[(\d+)\]"
    result = re.search(regex, log)
    print(result[1])
    print(type(result))


def second_regex():
    result = re.search(r"p.ng", "Pangea", re.IGNORECASE)
    print(result)
    print(result.span())


def third_regex():
    result = re.match(r"(p.ng)", "Pangea", re.IGNORECASE)
    print(result.groups())


def fourth_regex():
    list = ["python3 get", "python2 give", "python selenium"]
    for element in list:
        result = re.match("(p\w+)\d+", element)
        if result:
            print(result.groups())

# words inside [] are known are character class

index_method()
first_regex()
second_regex()
third_regex()
fourth_regex()

print(re.search(r"[Pp]ython", "Python is nice"))
# looks for any char that's not letter
print(re.search(r"[^a-zA-Z]", "This is a sentence"))
print(re.search(r"[^a-zA-Z ]", "This is a sentence"))
print(re.search(r"cat|dog", "Dog is big"))
print(re.search(r"cat|dog", "Cat is furry"))
print(re.search(r"cat|dog", "Dog and cat are terrestrial animals", re.IGNORECASE))
print(re.findall(r"cat|dog", "Dog and cat are terrestrial animals", re.IGNORECASE))
# match followed by any number of charachter
print(re.search(r"Py.*n", "Python Programming"))
print(re.search(r"Py[a-z]*n", "Python Programming"))
print(re.search(r"Py[a-z]*n", "Pyn"))
print(re.search(r"o+l+", "goldfish"))
print(re.search(r"o+l+", "woolly"))
print(re.search(r"o+l+", "boil"))
# ? 0 or 1 just the before's character
print(re.search(r"p?each", "To each their own"))

# escape character(match special character)
print(re.search(r"\.com", "welcome"))
print(re.search(r"\.com", "mydomain.com"))
# \w = alphanumeric(including numbers and _ too)
print(re.search(r"\w", "This is an example"))
print(re.search(r"\w*", "This_is: an example"))
print(re.search(r"\w+\s+\w+", "one"))
print(re.search(r"\w+\s+\w+", "username user_01"))
print(re.search(r"\w+\s+\w+", "shopping_list: milk, bread, eggs."))

print(re.search(r"^[a-zA-Z_]\w*$", "this_is_variable_name"))
print(re.search(r"^[a-zA-Z_]\w*$", "this isn't a valid variable"))
print(re.search(r"^[a-zA-Z_]\w*$", "my_variable1"))
print(re.search(r"^[a-zA-Z_]\w*$", "2my_variable1"))

def check_sentence(text):
    result = re.search(r"^[A-Z][a-z\s]+.*[\?|\.|\!]$", text)
    return result != None

print(check_sentence("Is this is a sentence?")) # True
print(check_sentence("is this is a sentence?")) # False
print(check_sentence("Hello")) # False
print(check_sentence("Is this is a sentence!")) # True
print(check_sentence("1-2-3-GO!")) # False
print(check_sentence("A star is born.")) # True


print("\nweb address checker function\n")

def check_web_address(text):
    pattern = r"\w*[\.|-|\+]*\.[a-zA-Z]+$"
    result = re.search(pattern, text)
    return result != None

print(check_web_address("gmail.com")) # True
print(check_web_address("www@google")) # False
print(check_web_address("www.Coursera.org")) # True
print(check_web_address("web-address.com/homepage")) # False
print(check_web_address("My_Favorite-Blog.US")) # True


print("\nClock checker\n")


def check_time(text):
    pattern = r"^[1-9]+:[00-59]+\s?[AM|PM|am|pm]"
    result = re.search(pattern, text)
    return result != None

print(check_time("12:45pm")) # True
print(check_time("9:59 AM")) # True
print(check_time("6:60am")) # False
print(check_time("five o'clock")) # False


print("\nContain Acronym function\n")

def contains_acronym(text):
    pattern = r"\([A-Z0-9][a-zA-Z0-9]+\)"
    result = re.search(pattern, text)
    return result != None

print(contains_acronym("Instant messaging (IM) is a set of communication technologies used for text-based communication")) # True
print(contains_acronym("American Standard Code for Information Interchange (ASCII) is a character encoding standard for electronic communication")) # True
print(contains_acronym("Please do NOT enter without permission!")) # False
print(contains_acronym("PostScript is a fourth-generation programming language (4GL)")) # True
print(contains_acronym("Have fun using a self-contained underwater breathing apparatus (Scuba)!")) # True

print("\nZip code US regex\n")

# (?<!^)aaa   =>  if there is no start of string position immediately to left of the current position
# (?|^)aaa   =>  same thing but with right side

import re
def check_zip_code (text):
    result = re.search(r"\w+.*\d\d\d\d\d[-\d\d\d\d]*", text)
    return result != None

print(check_zip_code("The zip codes for New York are 10001 thru 11104.")) # True
print(check_zip_code("90210 is a TV show")) # False
print(check_zip_code("Their address is: 123 Main Street, Anytown, AZ 85258-0001.")) # True
print(check_zip_code("The Parliament of Canada is at 111 Wellington St, Ottawa, ON K1A0A9.")) # False
