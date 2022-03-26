// main file

#include <iostream>
#include <cstring>

int arr[100001];

int main(int argc, char **argv) {
	int s = 0, b = 0;
	while(scanf("%d %d", &s, &b)) {
		if(!s && !b) break;
		memset(arr, 1, sizeof arr);
		for(size_t i = 0; i < b; i++) {
			int l = 0, r = 0;
			scanf("%d %d", &l, &r);
			for(size_t i = l; i < r; i++) arr[i] = 0;
			int lcount = 1;
			int fl = 0, fr = 0;
			while(lcount < s) {
				if(arr[lcount] == 0) break;
				else if(arr[lcount] == 1) {
					fl = lcount;
					break;
				}
				lcount++;
			}
			lcount = s;
			while(lcount > 0) {
				if(arr[lcount] == 0) break;
				else if(arr[lcount - 1] == 0 && arr[lcount] == 1) {
					fr = lcount;
					break;
				}
				lcount--;
			}
			if(fl == 0) printf("*");
			else printf("%d ", fl);
			if(fr == 0) printf(" *\n");
			else printf(" %d\n", fr);
		}
		puts("-");
	}
	return 0;
}