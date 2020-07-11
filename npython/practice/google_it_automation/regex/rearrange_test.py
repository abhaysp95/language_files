#!/usr/bin/env python3

'''
test cases for rearrange_name function
'''

import unittest
from rearrange_and_groups import rearrange_name


class TestRearrange(unittest.TestCase):
    '''class to make test cases'''

    def test_basic(self):
        '''basic testing'''
        testcase = 'Lovelace, Ada'
        expected = 'Ada Lovelace'
        self.assertEqual(rearrange_name(testcase), expected)

    def test_empty(self):
        '''give empty string(egde case)'''
        testcase = ''
        expected = ''
        # check the behaviour by assertEqual function
        self.assertEqual(rearrange_name(testcase), expected)

    def test_single(self):
        '''provide single name only'''
        testcase = 'John'
        expected = 'John'
        self.assertEqual(rearrange_name(testcase), expected)

    def test_double(self):
        '''test for double name'''
        testcase = 'Hopper, Grace M.'
        expected = 'Grace M. Hopper'
        self.assertEqual(rearrange_name(testcase), expected)


unittest.main()


# some other basic assertions are
# assertEqual(a, b) => a == b
# assertNotEqual(a, b) => a != b
# assertTrue(x) => bool(x) is True
# assertFalse(x) => bool(x) is False
# assertIs(a, b) => a is b
# assertIsNot(a, b) => a is not b
# assertIsNone(x) => x is None
# assertIsNotNone(x) => x in not None
# assertin(a, b) => a in b
# assertNotIn(a, b) => a not in b

# now, a = object to be checked
# b = classinfo(class, type or tuple of classes and types)
# assertIsInstace(a, b) => isinstance(a, b)
# assertNotIsInstance(a, b) => not isinstance(a, b)

# There's setUp and tearDown function and different decorators for unittest
# checkout =>
# https://docs.python.org/3/library/unittest.html#organizing-test-code
