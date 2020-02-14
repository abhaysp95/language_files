/** Name -> Abhay Shanker Pathak
Date -> 2020-02-14
Description -> Pattern 3, 10, 21, 36, ... for given value n print the series element of that place
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-14 */

#include<stdio.h>
#define size 110

int main(int argc, char *argv[]){
	int arr[size], i, j, c = 7, n;
	arr[0] = 3;
	printf("\nEnter the element: ");
	scanf("%d", &n);
	/* printf("%d",arr[0]); */
	for (i = 1, j = 0; i <= n+1; i++, j++ ) {
		arr[i] = arr[j] + c;
		c = c+4;
	}
	printf("\nValue is %d",arr[n-1]);
	return 0;
}
