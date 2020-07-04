#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-24
Description: checking out eval function
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-24
"""

# definition <<<
def dump(expression):
    result = eval(expression)
    print(expression, '=>', result, type(result))
# >>>

# <<<
dump("1")
dump("1.2")
dump("'string'")
dump("1.0 + 2.0")
dump("'*' * 10")
dump("len('world')")
# >>>
