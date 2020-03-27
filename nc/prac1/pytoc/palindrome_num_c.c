/** Name -> Abhay Shanker Pathak
Date -> 2020-03-24
Description -> Finding whether is palindrome or not
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-24 */

#include<stdio.h>

// main function <<<
int main(int argc, char *argv[]){
	long num, pnum, nnum = 0;
	int r;
	printf("Enter the num: ");
	scanf("%ld", &num);
	pnum = num;
	while (num != 0) {
		r = num % 10;
		num = num / 10;
		nnum = nnum * 10 + r;
	}
	if (pnum == nnum)
		printf("\nNumber is palindrome");
	else
		printf("\nNumber is not palindrome");
	return 0;
}
// >>>
