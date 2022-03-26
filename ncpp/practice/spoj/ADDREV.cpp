#include <iostream>
#include <cmath>

int reverse_num(int num) {
	int new_num = 0;
	int i = 0;
	while(num) {
		int rem = num % 10;
		new_num += (pow(10, (int)log10(num)) * rem);
		num /= 10;
	}
	return new_num;
}

int main(int argc, char** argv) {
	int t = 0;
	scanf("%d", &t);
	while(t--) {
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		int ra = reverse_num(a);
		int rb = reverse_num(b);
		printf("%d\n", reverse_num(ra + rb));
	}
	return 0;
}
