/** Name -> Abhay Shanker Pathak
Date -> 2020-02-08
Description -> Find GCD with recursion of two numbers
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-08 */

#include<stdio.h>

int gcd(int ,int );

int main(int argc, char *argv[]){
	int n1, n2, result;
	printf("\nEnter the numbers: ");
	scanf("%d%d",&n1,&n2);
	result = gcd(n1,n2);
	printf("\nGCD is %d ",result);
	return 0;
}

int gcd(int n1, int n2) {
	if (n2 != 0)
		return gcd (n2, n1%n2);
	else
		return n1;
	//return 0;		// There must be a return to work the function if it is not of void data type
	// don't use return 0 else it will return 0 use return gcd in if
}



