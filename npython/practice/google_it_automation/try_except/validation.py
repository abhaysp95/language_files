#!/usr/bin/env python3


def validate_user(username, minlen):
    # add assertion when you think something that shouldn't happen is happening
    # use assert, for situation that aren't expected but can cause our code to
    # misbehave
    assert type(username) == str, "username must be a string"
    if minlen < 1:
        # use raise to check for condition that we expect to happen during
        # normal execution of our code
        raise ValueError('minlen must be at least 1')
    if len(username) < minlen:
        return False
    if not username.isalnum():
        return False
    return True


if __name__ == "__main__":
    if validate_user('dakfjd', 0):
        print('Successful')
    else:
        print('Failed')
