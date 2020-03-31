/** Name -> Abhay Shanker Pathak
Date -> 2020-03-30
Description -> sorting array of strings to 4 ways
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> date */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	}
	printf("\nEntered strings are: ");
	for (int i = 0; i < count; i++) {
		// if not use ** , then use %p with *(word + i), or use *word[i]
		printf("\n%d string is: %s", i + i, *(word + i));
	}
	return 0;
}
// >>>
