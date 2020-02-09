/** Name -> Abhay Shanker Pathak
Date -> 2020-02-09
Description -> Check which is greater in 4 numbers by ternary method
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-09 */

#include<stdio.h>

int max_of_four(int ,int ,int ,int );

int main(int argc, char *argv[]){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int ans = max_of_four(a, b, c, d);
	printf("%d", ans);
	return 0;
}

int max_of_four(int a, int b, int c, int d) {
	int max=0;
	a>b?(a>c?(a>d?max=a:(max=d)):(c>d?max=c:(max=d))):(b>c?(b>d?max=b:(max=d)):(c>d?max=c:(max=d)));
	return max;
}

