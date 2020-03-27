/** Name -> Abhay Shanker Pathak
Date -> 2020-03-25
Description -> Check whether a substring found inside a string
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-25 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// main function <<<
int main(int argc, char *argv[]){
	char *string, *substring;
	string = malloc(256 * sizeof(char));
	substring = malloc(64 * sizeof(char));

	printf("\nEnter the string: \n");
	scanf("%[^\n]%*c", string);

	printf("\nEnter the substring: \n");
	scanf("%[^\n]%*c", substring);

	/* printf("String lenght: %zu", strlen(string)); */
	// %zu is used for size_t aka long unsigned int, value 0 or greater than 0
	/* printf("\nSubstring lenght: %zu", strlen(substring)); */

	for (int i = 0; i <= strlen(string) - strlen(substring); i++) {
		for (int j = 0; j < strlen(substring); j++) {
			if (*(string + i + j) != *(substring + j)) {
				break;
			}
			if (j == strlen(substring) - 1) {
				printf("\nSubstring found inside int at position %d ", i + 1);
				break;
			}
		}
	}
	free(string);
	free(substring);
	// will give no output if substring not found
	return 0;
}
// >>>
