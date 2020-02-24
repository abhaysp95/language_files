/** Name -> Abhay Shanker Pathak
Date -> 2020-02-24
Description -> Print digit frequency
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-24 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	char *s;
	int i, j, c = 0;
	s = malloc(100 * sizeof(char));
	scanf("%[^\n]", s);
	/* for(int i = 0; i < strlen(s); i++) { */
	/* 	printf("%c", *(s + i)); */
	/* } */
	int num[10] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
	for (i = 0; i < 10; i++) {
		c = 0;
		for (j =0; j < strlen(s); j++) {
			if (num[i] == *(s + j)) {
				c++;
			}
			//printf("%s", *(s + j));
		}
		printf("%d ", c);
	}
	return 0;
}
