#!/usr/bin/env python3

import unittest
from validation import validate_user


class TestValidation(unittest.TestCase):
    def test_valid(self):
        self.assertEqual(
            validate_user('validuser', 3),
            True)

    def test_too_short(self):
        self.assertEqual(
            validate_user('inv', 5),
            False)

    def test_invalide_chars(self):
        self.assertEqual(
            validate_user('invalid_user', 1),
            False)

    def test_invalid_minlen(self):
        # behind the scene this method is calling a
        # try-except block to check if does the
        # raise the error we want
        self.assertRaises(
            ValueError,
            validate_user,
            "user",
            -1)


# Run the test
unittest.main()
