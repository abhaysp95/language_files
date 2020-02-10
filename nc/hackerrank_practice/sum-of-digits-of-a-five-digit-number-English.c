/** Name -> Abhay Shanker Pathak
Date -> 2020-02-10
Description -> print sum of five digits number
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-10 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int n, r, sum = 0;
	printf("\nEnter the number of five digits: ");
	scanf("%d", &n);
	if (n >= 10000 && n <= 99999) {
		while (n > 0) {
			r = n % 10;
			n = n / 10;
			sum += r;
		}
	}
	printf("%d",sum);
	return 0;
}
