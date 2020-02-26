/** Name -> Abhay Shanker Pathak
Date -> 2020-02-26
Description -> Make the names in there short form
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-26 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	char *c, *space;
	int num, i, j = 0, num1;
	c = malloc(200*sizeof(char));
	space = malloc(40*sizeof(int));
	printf("Enter the name: ");
	scanf("%[^\n]", c);
	num = strlen(c);
	//printf("%d", num);
	//printf("\nEntered string is: ");
	for (i = 0; i < num; i++) {
		//printf("%c", *(c+i));
		if (*(c + i) == ' ') {
			*(space + j) = i;
			j++;
		}
	}
	num1 = strlen(space);
	/* printf("\nPosition of spaces: "); */
	/* for (i = 0; i < num1; i++){ */
	/* 	printf("%d\n", *(space + i)); */
	/* } */
	printf("Short Form: ");
	printf("%c. ", *(c + 0));
	for (j = 0; j < num1 - 1; j++) {
		printf("%c. ", *(c + *(space + j) + 1));
	}
	for (i = *(space + num1 - 1) + 1; i < num; i++) {
		printf("%c", *(c + i));
	}
	free(c);
	free(space);
	return 0;
}
