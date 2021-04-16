#!/usr/bin/env python3


def reverse_string_without_reversing_word(sentence, delim):
    word_list = sentence.split(delim)
    word_list.reverse()
    return ".".join(word_list)

num_sentences = int(input())

for x in range(num_sentences):
    sentence = input()
    print(reverse_string_without_reversing_word(sentence, '.'))
