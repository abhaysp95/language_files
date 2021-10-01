#include <iostream>
#include <cmath>

#define ARR_SZ 4

using ll = long long;

int main(int argc, char **argv) {
	int t = 0;
	scanf("%d", &t);
	while(t--) {
		int b = 0;
		ll p = 0;
		scanf("%d %lld", &b, &p);
		if(p == 0) {
			printf("%d\n", 1);
			continue;
		}
		int arr[ARR_SZ];
		arr[0] = b % 10;
		for(int i = 1; i < ARR_SZ; i++)
			arr[i] = (arr[i - 1] * b) % 10;
		int res = 0;
		if(p % ARR_SZ == 0) res = arr[ARR_SZ - 1];
		else res =  arr[(p % ARR_SZ) - 1];
		printf("%d\n", res);
	}
	return 0;
}


/** Note:
  1. With power increment by 1, there is repeatition of last digit after every 4th increment in the resultant number
  2. If you know the power 'p'(or the last digit of the resultant) of a certain number 'b', then for number 'b' * (pow(10, i)), where 'i' is whole number, you'll get same last digit for the power 'p'
  */
