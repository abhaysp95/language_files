/** Name -> Abhay Shanker Pathak
Date -> 2020-05-02
Description -> count occurence of each digits, 12 categories of input
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-05-02 */


#include<stdio.h>
#define SIZE 10

// main function <<<
int main(int argc, char* argv[]) {
	int c, i, nwhite, nother;
	int ndigit[SIZE];
	nwhite = nother = 0;

	for (i = 0; i < SIZE; ++i) {
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++ndigit[c-'0'];
		}
		else if (c == ' ' || c == '\n' || c == '\t') {
			++nwhite;
		}
		else {
			++nother;
		}
	}

	printf("digits = ");
	for (i = 0 ; i < SIZE; i++) {
		printf(" %d", ndigit[i]);
	}
	printf(", whitespace = %d, other = %d\n", nwhite, nother);
	return 0;
}
// >>>
