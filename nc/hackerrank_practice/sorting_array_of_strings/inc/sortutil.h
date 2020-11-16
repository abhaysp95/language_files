#pragma once
#include <string.h>
#include <stdlib.h>

#define LEN 26

//void string_sort(const char **arr, int cnt, int (*cmp_function)(const char* a, const char* b));
void string_sort(char **arr, int cnt, int (*cmp_function)(char* a, char* b));
int lexicographic_sort(char* a, char* b);
int lexicographic_sort_reverse(char* a, char* b);
int sort_by_length(char* a, char* b);
int sort_by_number_of_distinct_characters(char* a, char* b);
int distinct_chars(char* a);
void free_arr(char** arr, int n);