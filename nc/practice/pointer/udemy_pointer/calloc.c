// using calloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	char *s;
	int *p;
	char *copytemp;

	// malloc doesn't initializes(so garbage)
	s = (char *)malloc(6);
	for (int i = 0; i < 6; ++i) {
		printf ("s[%d] = %d\n", i, *(s + i));
	}
	free(s);
	printf("\n");

	// doing the same thing with calloc, on success it initializes with 0 as value to generic pointer else null pointer
	// NOTE: memory is freed out
	s = (char *)calloc(6, sizeof(char));
	for (int i = 0; i < 6; ++i) {
		printf ("s[%d] = %d\n", i, *(s + i));
	}
	free(s);
	printf ("\n");

	// in this example calloc allocates 6 integers
	p = (int *)calloc(6, sizeof(int));
	for (int i = 0; i < 6; ++i) {
		printf ("p[%d] = %d\n", i, *(p + i));
	}
	free(p);
	printf ("\n");

	s = (char *)calloc(6, sizeof(char));
	/*s = "Junior";*/
	strncpy(s, "Junior", 6);  // well, there's no place for '\0', how is it stopping then or not giving garbage values after
	printf("%s\n", s);
	free(s);

	// doing same thing with malloc
	s = (char *)malloc(6);
	strncpy(s, "Junior", 6);  // same here
	printf("%s\n", s);
	free(s);

	return 0;
}

/* also note that if some string is not null terminated then it'll give garbage */
