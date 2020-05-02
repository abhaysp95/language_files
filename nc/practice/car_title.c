/** Name -> Abhay Shanker Pathak
Date -> 2020-03-18
Description -> basic if/else
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> date */

#include<stdio.h>
#include<string.h>
#define size 7

// main function <<<
int main(int argc, char *argv[]){
	char car[][20] = {"audi", "mercedes", "porsche", "dodge", "playmoth", "bmw", "chevorlet"};
	int i = size - 1;
	printf("Entered words are: \n");
	for (int j = 0; j < size; j++) {
		printf("%s\n", car[j]);
	}

	while (i >= 0) {
		// this type of if gives error:- comparision with string literal results in unspecified behaviour
		/* if (*(car + i) == "bmw" || (car + i) == "dodge") */
		/* 	printf("%s in uppercase\n", car[i]); */
		/* else */
		/* 	printf("%s in titlecase\n", car[i]); */

		// this type of comparision is confusing, as it returns three values 0, -ve, +ve
		/* if (strcmp(car[i], "bmw") || strcmp(car[i], "dodge")) */

		if (strcmp(car[i], "bmw") == 0)
			printf("%s in uppercase\n", car[i]);
		else if (strcmp(car[i], "dodge") == 0)
			printf("%s in uppercase\n", car[i]);
		else
			printf("%s in titlecase\n", car[i]);
		printf("%d\n", (strcmp(car[i], "bmw")));
		printf("%d\n", (strcmp(car[i], "dodge")));
		i--;
	}
	return 0;
}
// >>>
