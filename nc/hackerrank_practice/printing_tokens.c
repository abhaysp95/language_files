/** Name -> Abhay Shanker Pathak
Date -> 2020-02-24
Description -> printing every word in new line
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-24 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	char *s = malloc(1024 * sizeof(char));
	scanf("%[^\n]", s);
	s = realloc(s, strlen(s) + 1); // increasing value of s one block
	int i;
	printf("%lu\n", strlen(s));
	/* for(i = 0; i < strlen(s); i++) { */
	/* 	printf("%c\n", *(s + i)); */
	/* } */
	for(i = 0; i < strlen(s); i++) {
		if(*(s + i) == ' ') {
			printf("\n");
			//i++;
		}
		else
			printf("%c", *(s + i));
	}
	return 0;
}
