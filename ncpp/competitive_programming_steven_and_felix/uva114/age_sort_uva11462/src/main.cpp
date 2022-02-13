// main file

#include <iostream>
#include <cstring>

int main(int argc, char **argv) {
	int len =0;
	while(scanf("%d", &len)) {
		if(len == 0) break;
		int inarr[len];
		int temparr[100];
		int outarr[len];
		memset(temparr, 0, sizeof(temparr));
		for(int i = 0; i < len; i++) {
			scanf("%d", inarr + i);
		}
		/** fill temp arr */
		for(int i = 0; i < len; i++) {
			temparr[inarr[i] - 1]++;
		}
		/** process temp arr */
		for(int i = 1; i < 100; i++) {
			temparr[i] += temparr[i - 1];
		}
		/** make output arr */
		for(int i = 0; i < len; i++) {
			int key = inarr[i] - 1;
			temparr[key]--;
			outarr[temparr[key]] = inarr[i];
		}
		for(int i = 0; i < len; i++) printf("%d ", outarr[i]);
		printf("\n");
	}
	return 0;
}