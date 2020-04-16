#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-11
Description: tell whether given sentence contains all the alphabets or not
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-11
"""


# main function <<<
def main():
    '''Building main function'''
    sentence = input('Enter the sentence: ')

    sent_lst = [x.lower() for x in sentence.split(' ')]
    print(sent_lst)

    sent_set = set()
    for word, _ in enumerate(sent_lst):
        for alphabet in sent_lst[word]:
            # if alphabet >= 97 and alphabet <= 122:
            # simplified chained comparision between operand
            if chr(97) <= alphabet <= chr(122):
                sent_set.add(alphabet)

    print(sent_set, '\n')
    print(sorted(sent_set))

    # although, > 26 is now not possible
    if len(sent_set) >= 26:
        print('Sentence contains all the alphabets')
        print('length is: ', len(sent_set))
    else:
        print('Sentence doesn\'t contains all the alphabets')
        print('length is: ', len(sent_set))
# >>>


if __name__ == "__main__":
    print(main.__doc__)
    main()
