#include <iostream>
#include <cstring>

#define SZ 256

int main()
{
	int col = 0;
	while(scanf("%d", &col)) {
		fgetc(stdin);
		if(col == 0) break;
		char buf[SZ] = {0}, ans[SZ] = {0};
		int count = 0;
		fgets(buf, SZ, stdin);
		size_t len = strlen(buf) - 1;
		if(buf[len] == '\n') buf[len] = '\0';
		// now this len is actual string length because '\n' is not present
		// anymore
		for(int i = 0; i < col; i++) {
			for(int k = 0; k < len; k+=(2*col)) {
				ans[count++] = buf[i + k];
				if((k + (2 * col)) <= len)
					ans[count++] = buf[2*col + k - i - 1];
			}
		}
		ans[count] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}
