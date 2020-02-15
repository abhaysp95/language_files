/** Name -> Abhay Shanker Pathak
Date -> 2020-02-14
Description -> Compare two strings
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-14 */

#include<stdio.h>
#include<string.h>
#define size 100

int main(int argc, char *argv[]){
	char str[size], str1[size], i, n;
	printf("\nEnter the strings: ");
	fgets(str, sizeof(str), stdin);
	fgets(str1, sizeof(str1), stdin);
	n = strcmp(str, str1);
	printf("n is %d", n);
	return 0;
}
