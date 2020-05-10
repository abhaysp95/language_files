#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|
#
# creating different functions for to implement complex number

import math


class ComplexNum(object):
    '''A class to implement complex number'''

    def __init__(self, r=0, i=0):
        self.real = r
        self.imag = i

    def __str__(self):
        '''returns a string representation of complex number'''
        # __str__ is called by str(object) and the built-in functions
        # like format() and print()
        # return value must be a string
        imag = self.imag
        join = ' + '
        if self.imag < 0:
            imag = -imag
            join = ' - '
        return '(' + str(self.real) + join + 'i' + str(imag) + ')'

    def getReal(self):
        '''returns real'''
        return self.real

    def getImag(self):
        '''returns imaginary'''
        return self.imag

    def abs(self):
        '''returns magnintude'''
        return math.sqrt(self.real * self.real + self.imag * self.imag)

    def conjugate(self):
        '''returns conjugate'''
        return ComplexNum(self.real, -self.imag)

    def __add__(self, oth):
        '''returns addition'''
        return ComplexNum(self.real + oth.real, self.imag + oth.imag)

    def __sub__(self, oth):
        '''returns substraction'''
        return ComplexNum(self.real - oth.real, self.imag - oth.imag)

    def __mul__(self, oth):
        '''returns multiplication'''
        return ComplexNum(self.real * oth.real - self.imag * oth.imag,
                          self.real * oth.imag - self.imag * oth.real)

    def __truediv(self, oth):
        '''return true division'''
        othc = oth.conjugate()
        absSq = oth.abs()
        absSq = absSq * absSq

        numr = self.othc
        try:
            return ComplexNum(numr.real / absSq, numr.imag / absSq)
        except:
            raise ValueError('Division by ' + str(oth) + ' is not defined')
        # if you are trying to compare to objects that you created class for
        # then __lt__, __le__, __gt__, __ge__, __eq__, __ne__ can be used
        # for arithmetic, __add__, __sub__, __mul__, __truediv__, __floordiv__
        # are given, __truediv__ = / and __floordiv__ = //


def main():
    '''inside main function'''
    z1 = ComplexNum()
    print('z1 = ' + z1)

    z2 = ComplexNum(2, 3)
    print('z2 = ' + z2)

    z3 = z2.conjugate()
    print('z3 = ', z3)

    z4 = z2 * z3
    print(z2, ' * ', z3, ' = ', z4)  # is calling __mul__ because * is used
    # z2 is bound to self and z3 is bound to oth

    print(z2, ' * ', z2, ' = ', z2 * z2)


if __name__ == "__main__":
    main()
