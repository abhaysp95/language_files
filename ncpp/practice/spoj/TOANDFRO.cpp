#include <iostream>
#include <cstring>

#define SZ 256

int main()
{
	int col = 0;
	while(scanf("%d", &col)) {
		fgetc(stdin);
		if(col == 0) break;
		char buf[SZ], ans[SZ];
		int count = 0;
		fgets(buf, SZ, stdin);
		size_t len = strlen(buf);
		if(buf[len] == '\n') buf[len] = '\0';
		for(int j = 0; j < col / 2; j++) {
			for(int i = 0; i < len; i+=(col * 2)) {
				ans[count++] = buf[i + j];
				if(i + col != len) ans[count++] = buf[i + (col * 2) - j - 1];
			}
		}
		ans[count] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}
