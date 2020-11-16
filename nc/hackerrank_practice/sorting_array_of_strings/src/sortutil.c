#include "../inc/sortutil.h"
#include <stdio.h>

void string_sort(char** arr, int cnt, int (*cmp_function)(char* a, char *b)) {
	int sorted = 0;
	int top = cnt - 1;
	while (!sorted) {
		sorted = 1;
		for (int i = 0; i < top; ++i) {
			if (cmp_function(*(arr + i), *(arr + i + 1)) > 0) {
				char* tmp = *(arr + i);
				*(arr + i) = *(arr + i + 1);
				*(arr + i + 1) = tmp;
				sorted = 0;
			}
		}
		top--;
	}
}

/*int lexicographic_sort(char* a, char* b) {
	if (strcmp(a, b) > 0) {
		char* temp = calloc(1024, sizeof(char));
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
		free(temp);
	}
	return 0;
}*/

int lexicographic_sort(char* a, char* b) {
	return strcmp(a, b);
}

/*int lexicographic_sort_reverse(char* a, char* b) {
	if (strcmp(a, b) < 0) {
		char* temp = calloc(1024, sizeof(char));
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
		free(temp);
	}
	return 0;
}*/

int lexicographic_sort_reverse(char* a, char* b) {
	return strcmp(b, a);
}

/*int sort_by_length(char* a, char* b) {
	if (strlen(a) > strlen(b)) {
		char* temp = calloc(strlen(a) + 1, sizeof(char));
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
	}
	else if (strlen(a) == strlen(b)) {
		if (strcmp(a, b) > 0) {
			char* temp = calloc(strlen(a) + 1, sizeof(char));
			strcpy(temp, a);
			strcpy(a, b);
			strcpy(b, temp);
		}
	}
	return 0;
}*/

int sort_by_length(char* a, char* b) {
	int res = strlen(a) - strlen(b);
	return res ? res : lexicographic_sort(a, b);
}

/*int distinct_chars(char* a) {
	int count = 0;
	for (int i = 0; i < strlen(a) - 1; ++i) {
		if (*(a + i) != *(a + i + 1)) {
			++count;
		}
	}
	return ++count;
}*/

int distinct_chars(char* a) {
	int* x = (int*)calloc(LEN, sizeof(int));
	int count = 0;
	/*for (int i = 0; i < strlen(a); ++i) {
		*(x + (*(a + i) - 'a')) += 1;
	}
	for (int i = 0; i < LEN; ++i) {
		if (*(x + i) >= 1) {
			++count;
		}
	}*/
	while (*a != '\0') {
		int chr = (*a++) - 'a';
		if (chr < LEN) {
			x[chr]++;
		}
	}
	for (int i = 0; i < LEN; ++i) {
		if (x[i]) { count++; }
	}
	return count;
}

/*int sort_by_number_of_distinct_characters(char* a, char* b) {
	if (distinct_chars(a) > distinct_chars(b)) {
		char* temp = calloc(1024, sizeof(char));
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
		free(temp);
	}
	else if (distinct_chars(a) == distinct_chars(b)) {
		if (strcmp(a, b) > 0) {
			char* temp = calloc(1024, sizeof(char));
			strcpy(temp, a);
			strcpy(a, b);
			strcpy(b, temp);
			free(temp);
		}
	}
	return 0;
}*/

int sort_by_number_of_distinct_characters(char* a, char* b) {
	int res = distinct_chars(a) - distinct_chars(b);
	return (res) ? res: lexicographic_sort(a, b);
}

void free_arr(char** arr, int num) {
	for (int i = 0; i < num; ++i) {
		free(*(arr + i));
	}
	free(arr);
}