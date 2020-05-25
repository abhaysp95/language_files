#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
sorting operation in python
"""


# here is how to sort a string S:
# All sorted lowercase letters are ahead of uppercase letters.
# All sorted uppercase letters are ahead of digits.
# All sorted odd digits are ahead of sorted even digits.


def main():
    '''inside main function'''
    string = input()
    slst = []
    nlst = list(map(int, filter(lambda x: x.isdigit(), string)))
    slst = list(filter(lambda x: x.isalpha(), string))
    # for bit in string:
    # if bit not in nlst:
    # slst.append(bit)

    evennumlst = []
    oddnumlst = []
    smallalphalst = []
    capalphalst = []
    for bit in nlst:
        if 0 <= bit <= 9:
            if bit % 2 == 0:
                evennumlst.append(bit)
            else:
                oddnumlst.append(bit)
    for bit in slst:
        if chr(65) <= bit <= chr(90):
            capalphalst.append(bit)
        else:
            smallalphalst.append(bit)

    evennumlst.sort()
    oddnumlst.sort()
    smallalphalst.sort()
    capalphalst.sort()

    slst = []
    slst = smallalphalst + capalphalst + oddnumlst + evennumlst
    print(''.join(map(str, slst)))


if __name__ == "__main__":
    main()
