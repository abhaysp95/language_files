#ifndef _QUERY_UTIL_H_
#define _QUERY_UTIL_H_

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char* get_input_text();
char**** get_document(char* text);

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n);
char** kth_sentence_in_mth_paragraph(char**** document, int k, int m);
char*** kth_paragraph(char**** document, int k);

char** string_split(char* text, char delim);

void print_word(char* word);
void print_sentence(char** sentence);
void print_paragraph(char*** paragraph);

void free_document(char**** document);

#endif