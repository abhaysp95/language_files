#!/usr/bin/env python3

'''
get memory and time difference between list and generators
'''

import memory_profiler
# import random
import timeit

import_module="""
import memory_profiler
import random
"""

print("Running third_code with number for timeit as 100")

print("Memory (before): {}Mb".format(memory_profiler.memory_usage()))

first_code="""
names = ['John', 'Corey', 'Adam', 'Steve', 'Rick', 'Thomas']
majors = ['Math', 'Engineering', 'CompSci', 'Arts', 'Buisness']

def people_list(num_people):
    result = []
    for i in range(num_people):
        person = {
            'id': i,
            'name': random.choice(names),
            'major': random.choice(majors)
        }
        result.append(person)
    return result
people=people_list(100000)
"""


second_code="""
names = ['John', 'Corey', 'Adam', 'Steve', 'Rick', 'Thomas']
majors = ['Math', 'Engineering', 'CompSci', 'Arts', 'Buisness']

def people_generator(num_people):
    for i in range(num_people):
        person = {
            'id': i,
            'name': random.choice(names),
            'major': random.choice(majors)
        }
        yield person
people=people_generator(100000)
"""

third_code="""
names = ['John', 'Corey', 'Adam', 'Steve', 'Rick', 'Thomas']
majors = ['Math', 'Engineering', 'CompSci', 'Arts', 'Buisness']

def people_generator(num_people):
    for i in range(num_people):
        person = {
            'id': i,
            'name': random.choice(names),
            'major': random.choice(majors)
        }
        yield person
people=list(people_generator(100000)
)"""

# code_to_run="people = people_list(1000000)"
time_taken = timeit.repeat(
    stmt=third_code,
    setup=import_module,
    number=100
)

print("Memory(after): {}Mb".format(memory_profiler.memory_usage()))
print('Took {} seconds'.format(time_taken))
