#!/usr/bin/env python3

import unittest
from getchars import lettercompiler


class TestCompiler(unittest.TestCase):
    def test_basic(self):
        testcase = "The best preparation for tomorrow is doing your best today."
        expected = ['b', 'a', 'a', 'e', 'a']
        self.assertEqual(lettercompiler(testcase), expected)

    def test_maybe_edge(self):
        testcase = "A b c d e f g h i j k l m n o p q r s t u v w x y z"
        expected = ['b', 'c']
        self.assertEqual(lettercompiler(testcase), expected)


# unittest.main() looks for sys.argv[]
unittest.main()
# for jupyter notebook, first arg is what starts jupyter kernel
# unittest.main(argv = ['first-arg-is-ignored'], exit = False)
