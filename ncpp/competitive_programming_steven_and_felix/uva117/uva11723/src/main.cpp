// main file

#include <iostream>
#include <cstdio>

int main(int argc, char **argv) {
	int r = 0, n = 0, count = 0;
	while(scanf("%d %d", &r, &n)) {
		if(r == 0 && n == 0) break;
		if ((n * 26) + n >= r) {
			int ans = 0;
			if (r > n) {
				if (r % n != 0) ans = r / n;
				else ans = (r / n) - 1;
			}
			printf("Case %d: %d\n", ++count, ans);
		}
		else printf("Case %d: impossible\n", ++count);
	}
	return 0;
}