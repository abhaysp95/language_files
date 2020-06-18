// how many stars will be there

#include<stdio.h>

void quizz(int);

void quizz(int i) {
	if (i > 1) {
		quizz(i / 2);
		quizz(i / 2);
	}
	printf(" * ");
}

int main(int argc, char *argv[]) {
	int num = 0;
	printf("Enter the number: ");
	scanf("%d", &num);
	quizz(num);
	return 0;
}
