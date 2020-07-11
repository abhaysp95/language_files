#!/usr/bin/env python3

'''
test for function get_email
'''

import unittest
from emails import get_email


class TestEmail(unittest.TestCase):
    '''some unittests'''
    def test_basic(self):
        '''basic test'''
        testcase = [None, "Kirk", "Nixon"]
        expected = "kirknixon@abc.edu"
        self.assertEqual(get_email(testcase), expected)

    def test_one_name(self):
        '''provide only one name'''
        testcase = [None, "Kirk"]
        expected = "Provided arguments are not enough"
        self.assertEqual(get_email(testcase), expected)

    def test_two_name(self):
        '''provide two name which is not in file'''
        testcase = [None, "Keanu", "Reeves"]
        expected = "Provided name isn't present in the file"
        self.assertEqual(get_email(testcase), expected)


if __name__ == "__main__":
    unittest.main()
