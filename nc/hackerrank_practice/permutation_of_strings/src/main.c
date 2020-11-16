// main file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b);
void permute_strings(char** s, int start, int end);

/*void swap(char* a, char* b) {
	[>printf("Swap a = %s, b = %s\n", a, b);<]
	[>char* temp = NULL;<]
	char temp[strlen(a)];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
	[>temp = a;
	a = b;
	b = a;<]
}*/

/*int count = 0;
void permute_strings(char** s, int start, int end) {
	if (start == end) {
		for (int i = 0; i <= end; ++i) {
			printf("%s%c", *(s + i), i == end ? '\n' : ' ');
		}
	}
	for (int index = start; index <= end; ++index) {
		[>printf("got index = %d, start = %d\n", index, start);<]
		[>printf("above first swap\n");<]
		swap(*(s + index), *(s + start));
		permute_strings(s , start + 1, end);
		[>printf("above second swap\n");<]
		swap(*(s + index), *(s + start));
		[>printf("end of a iteration\n");<]
	}
}*/

int next_permutation(int n, char** s) {
	/*permute_strings(s, 0, n - 1);*/
	int i = n - 1;
	// check for non-increasing suffix(means if all in decreasing order)
	// treating i - 1 as key
	// key will be that string which is biggest from the end side
	while ((i > 0) && (strcmp(*(s + (i - 1)), *(s + i)) >= 0)) { --i; }
	// if all total in decreasing order
	if (i <= 0) { return 0; }

	// swap key with just next successor in suffix
	int j = n - 1;
	// get the rightmost(just next) successor to key
	// j will be the string which is biggest to (key) string from end side
	while (strcmp(*(s + (i - 1)), *(s + j)) >= 0) { --j; }
	char temp[strlen(*(s))];
	/* char* temp  = *(s + (i - 1));*/ // since this is pointing to memory changing value of *(s + (i - 1)) will change value of temp after
	strcpy(temp, *(s + (i - 1)));
	strcpy(*(s + (i - 1)), *(s + j));
	strcpy(*(s + j), temp);
	// i can't be bigger than j

	// swap for lexographical order
	j = n - 1;
	while (i < j) {
		char temp[strlen(*(s))];
		strcpy(temp, *(s + i));
		strcpy(*(s + i), *(s + j));
		strcpy(*(s + j), temp);
		++i;
		--j;
	}
	return 1;
}

int main(int argc, char **argv) {
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; ++i) {
		s[i] = calloc(11, sizeof(char)); // allocate and initalize
		scanf("%s", s[i]);
	}
	do {
		for (int i = 0; i < n; ++i) {
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
		}
	} while(next_permutation(n, s));
	for (int i = 0; i < n; ++i) {
		free(s[i]);
	}
	free(s);
    return 0;
}