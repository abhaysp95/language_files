#!/usr/bin/env python3

'''
test the rearrange_and_groups's rearrange_name function
'''

import unittest
from rearrange_and_groups import rearrange_name


class diffTestCases():
    def __init__(self, provided, returned):
        self.provided = provided
        self.returned = returned

    def get_provided(self):
        return self.provided

    def get_returned(self):
        return self.returned


# inheriting TestCase class from unittest module to our TestRearrange class
class TestRearrange(unittest.TestCase):
    '''class to make automatic testing methods'''
    # Any method we define with prefix test will on our TestRearrange class
    # will automatically become test that can be run by testing framework
    def test_basic(self, case_count):
        '''basic testing'''
        # testcase = "Lovelace, Ada"
        # expected = "Ada Lovelace"
        testcase = case_count.get_provided()
        expected = case_count.get_returned()
        # assertEqual method(from TestCase class), basically says both of my
        # arguments are equal
        return self.assertEqual(rearrange_name(testcase), expected)


first_case = diffTestCases("Lovelace, Ada", "Ada Lovelace")
get_test1 = TestRearrange()
val = get_test1.test_basic(first_case)

print(val)

# this will run test for us
# unittest.main()
