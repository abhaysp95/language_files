#!/usr/bin/env python

str = 'X-DSPAM-Confidence:0.8475'

got_str = float(str[str.find(':') + 1:])

print('%g and type is %s' % (got_str, type(got_str)))
