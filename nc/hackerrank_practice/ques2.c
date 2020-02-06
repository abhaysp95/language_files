/** Name -> Abhay Shanker Pathak
Date -> 2020-02-06
Description -> take a char, string and line as STDIN and give to STDOUT
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-06 */

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
	char ch,s,sen;
	scanf("%c",&ch);
	scanf("%s",s);
	scanf("%[^\n]%*c",&sen);
	printf("%c",ch);
	puts(s);
	puts(sen);
	return 0;
}



