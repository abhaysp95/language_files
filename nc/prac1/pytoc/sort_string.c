/** Name -> Abhay Shanker Pathak
Date -> 2020-03-25
Description -> Sort string(sorting in ascending order)
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-25 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// main function <<<
int main(int argc, char *argv[]){
	//
	// variables <<<
	char *string, temp;
	int i, j;
	// >>>

	string = malloc(100 * sizeof(char));
	printf("\nEnter the string: ");
	scanf("%[^\n]%*c", string);
	/* scanf("%s", string); */ // this takes till space only

	/* printf("%c %c %d", *string, *(string + 1), *(string) == *(string + 1)); */

	for (i = 0; i < strlen(string) - 1; i++) {
		for (j = i + 1 ; j < strlen(string); j++) {
			/* if (*(string + j) == '\0') { */
			/* 	continue; */
			/* } */
			if (*(string + i) > *(string + j)) {
				temp = *(string + i);
				*(string + i) = *(string + j);
				*(string + j) = temp;
			}
		}
	}

	/* printf("%s", string); */
	for (i =0; i <= strlen(string); i++) {
		printf("%c", *(string + i));
	}

	return 0;
}
// >>>
