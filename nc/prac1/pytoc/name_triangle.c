/** Name -> Abhay Shanker Pathak
Date -> 2020-03-24
Description -> Making name right angle triangle
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-24 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// main function <<<
int main(int argc, char *argv[]){
	char *c;
	int i, j;
	/* printf("\nEnter size of string: "); */
	/* scanf("%d", &n); */
	c = (char *)malloc(50 * sizeof(char));
	printf("\nEnter the string: ");
	i = 0;
	/* do { */
	/* 	scanf("%c", (c + i)); */
	/* 	i++; */
	/* } while(*c != '\n'); */
	/* scanf("%s", c); */
	/* fgets(c, sizeof(c), stdin); */
	scanf("%[^\n]%*c", c);
	/* printf("\nLength of the string is: %lu", strlen(c)); */
	for (i = 0; i < strlen(c); i++) {
		for (j = 0; j < i + 1; j++) {
			printf("%c", *(c + j));
		}
		printf("\n");
	}
	free(c);
	return 0;
}
// >>>
