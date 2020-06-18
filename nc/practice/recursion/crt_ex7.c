/**

Abhay Shanker Pathak
abhaysp9955@gmail.com
https://github.com/coolabhays


check whether the entered number is prime or not by recursion */


#include<stdio.h>

int flag = 1;

int if_prime(int number, int count) {
	if (flag == 1) {
		if (number == 1 || number == 2) {
			flag = 1;
		}
		else {
			if (count <= number/2) {
				if (number % count == 0 && count != 1) {
					flag = 0;
				}
				else {
					if_prime(number, count + 1);
				}
			}
			else {
				flag = 1;
			}
		}
	}
	else if (flag == 0) {
		return 0;
	}
	return flag;
}

int if_prime2(int number, int count) {
	if (count == 1) {
		return 1;
	}
	else {
		if (number % count == 0) {
			return 0;
		}
		else {
			if_prime2(number, count - 1);
		}
	}
}

// main function
int main(int argc, char* argv[]) {
	int num = 0, res = 0;
	printf("Enter the number: ");
	scanf("%d", &num);
	// res = if_prime(num, 1);
	res = if_prime2(num, num / 2);
	res == 1
		? printf("Number %d is prime", num)
		: printf("Number %d is non prime", num);
	return 0;
}
