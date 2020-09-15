// relation between array, its address and pointer

#include <stdio.h>

int main(int argc, char **argv) {
	char str1[] = "hello";
	char *str2 = "goodbye";
	char *str3 = str1;  // storing the address of str1, as array's name is its address too
	printf("%d %d %s\n", str1, &str1, str1);
	printf("%d %d %s\n", &str2, str2, str2);
	printf("%d %d %s\n", &str3, str3, str3);
	return 0;
}
