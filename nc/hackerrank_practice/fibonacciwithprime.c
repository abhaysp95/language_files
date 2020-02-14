/** Name -> Abhay Shanker Pathak
Date -> 2020-02-14
Description -> Series mix of fibonacci and prime numbers
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-14 */

#include<stdio.h>
#define size 1000

int main(int argc, char *argv[]){
	int num, a = 1, b = 1, c, i, j, flag, pos, d = 0;
	printf("\nEnter the position: ");
	scanf("%d", &num);
	if ((num + 1)%2 == 0) {
		if (num == 1 || num ==3) {
			printf("1");
		}
		else {
			for (i = 2; i < (num + 1)/2; i++) {
				c = a + b;
				a = b;
				b = c;
			}
			printf("\nNumber: %d",c);
		}
	}
	else {
		pos = num/2;
		if (num == 2) {
			printf("2");
		}
		else {
			d = 1;
			for (i = 3; i < size; i++) {
				flag = 0;
				for (j = 2; j < i; j++ ) {
					if (i%j == 0){
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					d++;
				}
				if (d == pos) {
					printf("%d ",i);
					break;
				}
			}
		}
	}
	return 0;
}
