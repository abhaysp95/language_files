/** Name -> Abhay Shanker Pathak
Date -> 2020-03-11
Description -> Pattern matching in string
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-11 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	char *str1, *str2;
	str1 = (char *)malloc(sizeof(char));
	str2 = (char *)malloc(sizeof(char));
	printf("\nEnter the string(big): ");
	scanf("%[^\n]", str1);
	printf("\nEnter the string(small): ");
	scanf("%[^\n]", str2);
	int l1, l2;
	l1 = strlen(str1);
	l2 = strlen(str2);
	str1 = realloc(str1, (l1 + 1) * sizeof(char));
	str2 = realloc(str2, (l2 + 1) * sizeof(char));
	printf("\n%d\t%d", l1, l2);
	return 0;
}

// incomplete right now
