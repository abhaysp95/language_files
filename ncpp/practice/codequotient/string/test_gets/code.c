#include <stdio.h>
#include <string.h>

int main() {
	char c1[1024], c2[1024];
	/*scanf("%[^\n]%*c", c1);*/
	fgets(c1, 1023, stdin);
	// strcspn return the count of the initial characters from string1 that are not part of string2
	c1[strcspn(c1, "\r\n")] = '\0';
	fgets(c2, 1023, stdin);
	c2[strcspn(c2, "\r\n")] = '\0';
	int res = strncmp(c1, c2, 1023);
	printf("%d\n", res);
	printf("%s\n", (res == 0 ? "Equal" : (res > 0 ? "Large" : "Small")));
}
