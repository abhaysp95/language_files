#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
creating a minion game(why minion IDK)
"""


def minion_game(got_str):
    '''function to get result'''
    vowels = ['A', 'E', 'I', 'O', 'U']

    kev_words = 0
    stu_words = 0

    for count, _ in enumerate(got_str):
        if got_str[count] in vowels:
            kev_words += len(got_str) - count
        else:
            stu_words += len(got_str) - count

    if kev_words > stu_words:
        # print('Kevin', kev_words)
        yield 'Kevin'
        yield kev_words
    elif kev_words < stu_words:
        # print('Stuart', stu_words)
        yield 'Stuart'
        yield stu_words
    else:
        yield 'Draw'


def minion_game2(got_str):
    '''another method'''
    vowel = 'aeiou'.upper()

    str_len = len(got_str)
    kev_score = sum((str_len - count)
                    for count in range(str_len) if got_str[count] in vowel)
    stu_score = (str_len * (str_len + 1)) // 2 - kev_score

    # print('Kevin %d' % kev_score) => Kevin 9
    if kev_score - stu_score > 0:
        yield 'Kevin'
        yield kev_score
    elif stu_score - kev_score > 0:
        yield 'Stuart'
        yield stu_score
    else:
        yield 'Draw'


def main():
    '''inside main function'''
    result = minion_game2(input())
    print(' '.join(map(str, result)))


if __name__ == "__main__":
    main()
