/** Name -> Abhay Shanker Pathak
Date -> 2020-02-15
Description -> Add two long integers
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-15 */

#include<stdio.h>
#include<string.h>
#define size 100

int main(int argc, char *argv[]){
	char s1[size], s2[size];
	printf("Enter first numbers: ");
	fgets(s1, sizeof(s1), stdin);
	printf("Enter second number: ");
	fgets(s2, sizeof(s2), stdin);
	printf("Size of first number set: %ld",strlen(s1));
	printf("Size of second number set: %ld",strlen(s2));
	return 0;
}
