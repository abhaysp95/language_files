// a example of scope of variables

#include <stdio.h>

int func1();
int func2();

// main function
int main(int argc, char* argv[]) {
	int x, y, s = 2;
	s *= 3;  // don't think this is a pointer => s = 6
	y = func1(s);
	x = func2(s);
	printf("%d %d %d\n", s, x, y);
	return 0;
}

int t = 8;

int func1(int a) {
	a += -5;
	t -= 4;
	return (a + t);  // 5
}

int func2(int a) {
	a = 1;
	t += a;
	return (a + t);  // 6
}
