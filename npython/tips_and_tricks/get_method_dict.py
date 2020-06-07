#!/usr/bin/env python

name_for_userid = {
    382: 'Alice',
    590: 'Bob',
    952: 'Gilbert'
}


def greeting(userid):
    # .get(two, args) returns the value for key otherwise default arg
    print('Hi! %s' % name_for_userid.get(userid, 'there'))
    # print('Hi!', name_for_userid.get(userid, 'there'))


greeting(382)
greeting(3999)
