/** Name -> Abhay Shanker Pathak
Date -> 2020-02-13
Description -> program to learn gdb
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-13 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int out = 0, tot = 0, cnt = 0;
	int val[] = {5, 54, 76, 91, 35, 27, 45, 15, 99, };

	while (cnt < 10) {
		out = val[cnt];
		tot = tot + 0xffffffff/out;
		cnt++;
	}
	printf("\nTotal = [%d]\n", tot);
	return 0;
}
