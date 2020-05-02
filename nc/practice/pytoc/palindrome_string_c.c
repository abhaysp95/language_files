/** Name -> Abhay Shanker Pathak
Date -> 2020-03-24
Description -> Entering three strings and checking if combined is palindrome or not
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-24 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *strv(char *);

// main function <<<
int main(int argc, char *argv[]){
	char *str1, *str2, *str3, *str, *strev;
	str1 = malloc(100*sizeof(char));
	str2 = malloc(100*sizeof(char));
	str3 = malloc(100*sizeof(char));
	printf("Enter first string: \n");
	scanf("%[^\n]%*c", str1);
	printf("Enter second string: \n");
	scanf("%[^\n]%*c", str2);
	printf("Enter third string: \n");
	scanf("%[^\n]%*c", str3);

	/* printf("length: %lu\n", strlen(str1)); */
	/* printf("length: %lu\n", strlen(str2)); */
	/* printf("length: %lu\n", strlen(str3)); */
	int size = strlen(str1) + strlen(str2) + strlen(str3);
	str = malloc(size *sizeof(char));
	strev = malloc(size *sizeof(char));
	str = strcat(str1, str2);
	str = strcat(str, str3);

	printf("String before reverse: ");
	for (int i = 0; i < size; i++)
		printf("%c", *(str + i));

	/* strev = strrev(str); can't use it in linux, maybe*/
	for (int i = 0; i < size; i++) {
		*(strev + i) = *(str + i);
	}

	strev = strv(strev);
	printf("\nString 2 after reverse: ");
	for (int i = 0; i < size; i++)
		printf("%c", *(strev + i));

	printf("\nString 1 after reverse: ");
	for (int i = 0; i < size; i++)
		printf("%c", *(str + i));

	printf("\nvalue of strcmp = %d\n", strcmp(str, strev));

	if (strcmp(str, strev) == 0)
		printf("String is palindrome");
	else
		printf("String is not palindrome");
	return 0;
}
// >>>

// string reverse function <<<
char *strv(char * strt) {
	char *i, *j, c;
	/* if (!str || !*str) */
	/* 	return str; */
	for (i = strt, j = strt + (strlen(strt) - 1); i < j; i++, j--) {
		c = *i;
		*i = *j;
		*j = c;
	}
	return strt;
}
// >>>
