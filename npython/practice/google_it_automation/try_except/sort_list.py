#!/usr/bin/env python3

my_word_list = ['east', 'after', 'up', 'over', 'inside']
my_new_list = [6, 3, 8, "12", 42]


def organize_list(mylist):
    mylist.sort()
    return mylist


def organize_list2(mylist):
    for item in mylist:
        raise TypeError('Comparision between wrong class objects')

    mylist.sort()
    return mylist


print(organize_list2(my_word_list))
print(organize_list2(my_new_list))
