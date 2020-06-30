#!/usr/bin/env python


def tried_attempt(sentence):
    words = sentence.split()

    len_list = [len(word) for word in words]
    len_list.sort(reverse=True)
    sorted_list = []

    for len_word in len_list:
        for word in words:
            if len_word == len(word) and word not in sorted_list:
                sorted_list.append(word)
    print(sorted_list)


def books_attempt(sentence):
    '''attempting DSU'''
    words = sentence.split()
    new_tuple = list()
    # D => decoreate, list of tuples with one or more sort keys preceeding
    # the element
    for word in words:
        new_tuple.append((len(word), word))
    print(new_tuple)

    # S => sort, sort the list of tuple
    new_tuple.sort(reverse=True)
    print(new_tuple)

    result = list()
    # U => undecorate, extract the sorted elements in the sequence
    for length, word in new_tuple:
        result.append(word)

    print(result)


def main():
    txt = 'but soft what light in younder window breaks'
    books_attempt(txt)


if __name__ == "__main__":
    main()
