#include <iostream>
#include <cstring>

#define MAXN 100000
int arr[MAXN + 1];

int main(int argc, char** argv) {
	int t = 0;
	scanf("%d", &t);
	while(t--) {
		int num = 0;
		scanf("%d", &num);
		memset(arr, 0, sizeof(arr));
		int count = MAXN;
		/* insert first number */
		int num_bak = num;
		while(num_bak) {
			arr[count--] = num_bak % 10;
			num_bak /= 10;
		}
		num--;
		/** multiply the numbers */
		int carry = 0, cp = MAXN;
		while(num) {
			for(cp = MAXN; cp > count; cp--) {
				int res = (arr[cp] * num) + carry;
				arr[cp] = res % 10;
				carry = res / 10;
			}
			while(carry) {
				int rem = carry % 10;
				arr[cp--] = rem;
				carry /= 10;
			}
			count = (cp < count) ? cp : count;
			num--;
		}
		for(int i = count + 1; i <= MAXN; i++) printf("%d", arr[i]);
		printf("\n");
	}
	return 0;
}
