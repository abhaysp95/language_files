/** Name -> Abhay Shanker Pathak
Date ->
Description ->
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit ->  */

#include<stdio.h>
#define size 100

int main(int argc, char *argv[]){
	char str[size], i = 0;
	printf("\nEnter the string- ");
	fgets(str, sizeof(str), stdin);
	while (str[i] != '\0') {
		i++;
	}
	printf("\nLength of String: %d", i-1);
	return 0;
}
