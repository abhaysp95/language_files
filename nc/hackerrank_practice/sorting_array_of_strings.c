/** Name -> Abhay Shanker Pathak
Date -> 2020-03-30
Description -> sorting array of strings to 4 ways
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> date */

// header files <<<
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// >>>

// function predeclaration <<<
void firstsort(int , char **);
void secondsort(int , char **);
void thirdsort(int , char **);
void fourthsort(int , char **);
// >>>

// main function <<<
int main(int argc, char *argv[]){
	int count;
	char **word;

	printf("Enter the count of string: ");
	scanf("%d", &count);
	printf("\nEnter the strings: ");
	word = malloc(sizeof(char *) * count);
	for (int i = 0; i < count; i++) {
		// or use word[i]
		*(word + i) = malloc(100 * sizeof(char));

		printf("\nEnter the %d string: ", i + 1);
		scanf("%s", *(word + i));
		// no need of \n in scanf, because we already press <C-R> to give input
	}
	printf("\nEntered strings are: ");
	for (int i = 0; i < count; i++) {
		// if not use ** , then use %p with *(word + i), or use *word[i]
		printf("\n%d string is: %s", i + 1, *(word + i));
	}

	// string sorted in lexographically non-decreasing order
	firstsort(count, word);

	printf("\n String after first sort: ");
	for (int i = 0; i < count; i++) {
		printf("\n%s", *(word + i));
	}

	//string sorted in lexographically non-increasing order
	secondsort(count, word);

	printf("\nSecond type of sort is: ");
	for (int i = 0; i < count; i++) {
		printf("\n%s", *(word + i));
	}

	// string sorting according to non-decreasing distinct elemetns presence,
	// if same distinct elements then sort lexographically increasing order
	thirdsort(count, word);

	printf("\nThird type of sort is: ");
	for (int i = 0; i < count; i++) {
		printf("\n%s", *(word + i));
	}

	// string sorting to sort in non-decreasing order of their length,
	// if same length then lexographically small string should appear first
	fourthsort(count, word);

	printf("\nFourth type of sort is: ");
	for (int i = 0; i < count; i++) {
		printf("\n%s", *(word + i));
	}

	return 0;
}
// >>>

// function for first type of sort <<<
void firstsort(int count, char **arr) {
	char *temp;
	int res;
	temp = malloc(sizeof(char) * 100);
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			res = strcmp(*(arr + i), *(arr + j));
			if (res > 0) {
				temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}
// >>>

// function for second type of sort <<<
void secondsort(int count, char **arr) {
	char *temp;
	int res;
	temp = malloc(sizeof(char) * 100);
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			res = strcmp(*(arr + i), *(arr + j));
			if (res < 0) {
				temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}
// >>>

// function for sorting of third type <<<
void thirdsort(int count, char **wordlist) {
	int *distinct;
	int res = 1, i, j, temp;
	int wrdcnt, chrcnt, achrcnt;
	char *temp_word = malloc(sizeof(char) * 100);
	// wrdcnt = word count
	// chrcnt = char count
	// achrcnt = another char count, but behind chrcnt

	// getting string lengths first
	for (i = 0; i < count; i++) {
		printf("\nstring's length: %zu\n", strlen(*(wordlist + i)));
	}

	distinct = malloc(sizeof(int) * (count + 1));
	for (wrdcnt = 0; wrdcnt < count; wrdcnt++) {
		res = 1;
		/* printf("wrdcnt is: %d\n", wrdcnt); */
		for (chrcnt = 1; chrcnt < strlen(*(wordlist + wrdcnt)); chrcnt++) {
			/* printf("chrcnt is: %d\n", chrcnt); */
			for (achrcnt = 0; achrcnt < chrcnt; achrcnt++) {
				if(*(*(wordlist + wrdcnt) + chrcnt) == *(*(wordlist + wrdcnt) + achrcnt)) {
					/* printf("\ninside if\n"); */
					break;
				}
				/* printf("after comp 1\n"); */
			}
			/* printf("after comp 2\n"); */
			if (chrcnt == achrcnt) {
				res++;
				/* printf("res is: %d\n", res); */
			}
			/* printf("after comp 2\n"); */
		}
		/* printf("distinct %d\n", res); */
		*(distinct + (wrdcnt)) = res;
		/* for (i = 0; i <= wrdcnt; i++) { */
		/* 	printf("dstnct is: %d\n", *(distinct + i)); */
		/* } */
	}

	printf("printing distinct elements: \n");
	for (i = 0; i < count; i++) {
		printf("%d\t", *(distinct + i));
	}

	// sorting according to non-decreasing distinct elements
	for (i = 0; i < count - 1; i++) {
		for (j = i + 1; j < count; j++) {
			if (*(distinct + i) > *(distinct + j)) {
				temp = *(distinct + i);
				*(distinct + i) = *(distinct + j);
				*(distinct + j) = temp;

				temp_word = *(wordlist + i);
				*(wordlist + i) = *(wordlist + j);
				*(wordlist + j) = temp_word;
			}
			else if(*(distinct + i) == *(distinct + j)) {
				res = strcmp(*(wordlist + i), *(wordlist + j));
				if (res > 0)
				temp_word = *(wordlist + i);
				*(wordlist + i) = *(wordlist + j);
				*(wordlist + j) = temp_word;
			}
		}
	}
}
// >>>

// function for sorting of fourth type <<<
void fourthsort(int count, char **wordlist) {
	int i, j;
	int res;
	char *temp_word = malloc(sizeof(char) * 100);

	/* for (i = 0; i < count; i++) { */
	/* 	printf("string is %s", *(wordlist + i)); */
	/* 	printf("\nstring length is %zu\n", strlen(*(wordlist + i))); */
	/* } */
	// sorting wordlist according to increasing order of their length, if same then lexographically increasing order
	for (i = 0; i < count -1; i++) {
		for (j = i + 1; j < count; j++) {
			if (strlen(*(wordlist + i)) > strlen(*(wordlist + j))) {
				temp_word = *(wordlist + i);
				*(wordlist + i) = *(wordlist + j);
				*(wordlist + j) = temp_word;
			}
			else if(strlen(*(wordlist + i)) == strlen(*(wordlist + j))) {
				res = strcmp(*(wordlist + i), *(wordlist + j));
				if (res > 0) {
					temp_word = *(wordlist + i);
					*(wordlist + i) = *(wordlist + j);
					*(wordlist + j) = temp_word;
				}
			}
		}
	}
}
// >>>
