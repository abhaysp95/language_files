#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-13
Description: if combination of strings is complete or not
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-13
"""

# import pdb


# creating main function <<<
def main():
    '''Entering main function'''
    # count1 = int(input('Enter first count: '))
    # count2 = int(input('Enter seconed count: '))

    string1 = input('Enter first set: ')
    string2 = input('Enter second set: ')

    # string3 = string1 + string2
    # this adds last word of first string and first word of
    # second string without space

    # init_lst = [x for x in string3.split(' ')]
    init_lst = []
    for word in string1.split(' '):
        init_lst.append(word)

    for word in string2.split(' '):
        init_lst.append(word)

    # num_lst = []
    new_lst = []
    count = 0

    # pdb.set_trace()
    for word in init_lst:
        # this should overwrite the previous value of init_set
        for word2 in init_lst:
            # if word and word2 not in new_lst:
            if word2 + word not in new_lst:
                init_set = set(word)
                init_set.update(set(word2))
                if len(init_set) >= 26:
                    # if len(init_set) not in num_lst:
                    #     num_lst.append(len(init_set))
                    count = count + 1
                    new_lst.append(word + word2)
                    # new_lst.append(word2)
                    print('word is: ', word)
                    print('word2 is: ', word2)

    print(new_lst)
    print('Total complete pairs will be: ', count)
# >>>


if __name__ == "__main__":
    print(main.__doc__)
    main()
