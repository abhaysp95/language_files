// main file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strtok_code(char* str1, char delim) {
	char* res = NULL;
	res = (char*)calloc(strlen(str1) + 1, sizeof(char));
	char* token = strtok(str1, &delim);
	while(token != NULL) {
		/*printf("%s", token);*/
		if(res == NULL) strncpy(res, token, strlen(token));
		else strncat(res, token, strlen(token));
		res[strlen(res)] = '\n';
		token = strtok(NULL, &delim);
	}
	return res;
}

int main(int argc, char **argv) {
	int t = 0, i, j = 0;
	char str[50];
	char ch[2];
	char* res = NULL;
	scanf("%d", &t);
	while(t--) {
		printf("test case:\n");
		scanf("%s %c", str, ch);
		res = strtok_code(str, ch[0]);
		printf("%s", res);
		free(res);
		res = NULL;
	}
	return 0;
}