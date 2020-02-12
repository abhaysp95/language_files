/** Name -> Abhay Shanker Pathak
Date -> 2020-02-12
Description -> same bitwise problem
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-12 */

#include<stdio.h>

void calculate_the_maximum(int ,int );

int main(int argc, char *argv[]){
	int n, k;
	scanf("%d %d", &n, &k);
	calculate_the_maximum(n, k);
	return 0;
}

void calculate_the_maximum(int n, int k) {
	int i = 0, j = 0;
	int and, max_and = 0;
	int or, max_or = 0;
	int xor, max_xor = 0;
	// i is working as a and j as b,
	for (i = 1; i <=n; ++i) {
		for (j = 1; j <=n; j++) {
			// if a < b
			if (i < j) {
				and = i & j;
				if (and > max_and && and < k) {
					max_and = and;
				}

				or = i | j;
				if (or > max_or && or < k) {
					max_or = or;
				}

				xor = i ^ j;
				if (xor > max_xor && xor < k) {
					max_xor = xor;
				}

			}
		}
	}
	printf("%d\n%d\n%d",max_and, max_or, max_xor);
}

