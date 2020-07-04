#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
basic file reading
"""


def main():
    '''main function'''
    file = open('file.txt', 'r')
    # if no method given, it'll clear the contents of file
    fread = file.readlines()
    print(type(fread))
    # print(fread)

    # methods to remove '\n' when last one isn't containg it
    newlist = []
    for line in fread:
        if line[-1] == '\n':
            # all line except the last character
            newlist.append(line[:-1])
        else:
            newlist.append(line)
    print(newlist)

    # another method

    newlist2 = []
    for line in fread[:-1]:
        newlist2.append(line[:-1])
    newlist2.append(fread[-1])
    print(newlist2)

    newlist3 = []
    for line in fread:
        # you can also use just strip
        newlist3.append(line.rstrip('\n'))
    print(newlist3)

    newlist4 = []
    for line in fread:
        newlist4.append(line.strip())
    file.close()


if __name__ == "__main__":
    main()
