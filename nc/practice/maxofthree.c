/** Name -> Abhay Shanker Pathak
Date -> 2020-02-06
Description -> Find max of three elements(using ternary operators)
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-06 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int a,b,c,large;
	printf("\nEnter three numbers: ");
	scanf("%d%d%d",&a,&b,&c);
	large = a>c?(a>b?a:c):(b>c?b:c);
	printf("\nLargest element is %d",large);
	return 0;
}
