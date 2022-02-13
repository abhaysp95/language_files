// main file

#include <iostream>
#include <cstring>
#include <numeric>

using namespace std;

int pages[10];

int main(int argc, char **argv) {
	int T = 0, counter = 0;;
	scanf("%d", &T);
	while(T--) {
		memset(pages, 0, sizeof(pages));
		int n = 0;
		scanf("%d", &n);
		for(size_t i = 0; i < n; i++) {
			scanf("%d", &pages[i]);
		}
		float mean = accumulate(pages, pages + n, 0) / float(n) ;
		int res = 0;
		if (pages[0] < pages[n - 1]) {
			for(int i = 0; i < n - 1; i++) {
				if(pages[i + 1] >= mean) {
					res = (pages[i + 1] - mean > mean - pages[i])
						? pages[i] : pages[i + 1];
					break;
				}
			}
		}
		else {
			for(int i = 0; i < n - 1; i++) {
				if(pages[i + 1] <= mean) {
					res = (pages[i] - mean > mean - pages[i + 1])
						? pages[i + 1] : pages[i];
					break;
				}
			}
		}
		printf("Case %d: %d\n", ++counter, res);
	}
	return 0;
}