/** Name -> Abhay Shanker Pathak
Date -> 2020-03-24
Description -> Remove everything except alphabet
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-24 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// main function <<<
int main(int argc, char *argv[]){
	char *str;
	str = (char *)malloc(sizeof(char));
	printf("\nEnter the string: ");
	scanf("%[^\n]%*c", str);
	for (int i = 0; i < strlen(str); i++) {
		if ( *(str + i) >= 65 && *(str + i) <= 90)
			printf("%c", *(str + i));
		else if ( *(str + i) >= 97 && *(str + i) <= 122)
			printf("%c", *(str + i));
	}
	return 0;
}
// >>>
