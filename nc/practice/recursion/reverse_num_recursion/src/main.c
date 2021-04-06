// main file

#include <stdio.h>
#include <math.h>

int reverse_loop(int num) {
	int rev = 0;
	while (num > 0) {
		rev = rev * 10 + (num % 10);
		num /= 10;
	}
	return rev;
}

int reverse_rec_two_param(int num, int rev_num) {
	if (num == 0) {
		return rev_num;
	}
	rev_num = rev_num * 10 + (num % 10);
	return reverse_rec_two_param(num / 10, rev_num);
}

int reverse_rec_best(int num) {
	if (num / 10 == 0) {
		return num;
	}
	return ((num % 10) * (pow(10, (int)log10(num)))) + reverse_rec_best(num / 10);
}

int main(int argc, char **argv) {
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", reverse_rec_two_param(num, 0));
	return 0;
}