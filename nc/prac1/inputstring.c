/** Name -> Abhay Shanker Pathak
Date -> 2020-02-09
Description -> take string as stdin
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-09 */

#include<stdio.h>
#define size 50

int main(int argc, char *argv[]){
	char s[size],ch;
	printf("\nEnter the string 3: ");
	fgets(s, sizeof(s), stdin);
	printf("\n3: ");
	puts(s);
	printf("\nEnter the string 1: ");
	scanf("%c",&ch);
	printf("\n1: %c",ch);
	printf("\nEnter the string 2: ");
	scanf("%s", s);
	printf("\n2: %s", s);
	scanf("\n");
	printf("\nEnter the string 4: ");
	scanf("%[^\n]%*c",s);
	printf("\n4: ");
	puts(s);
	return 0;
}
