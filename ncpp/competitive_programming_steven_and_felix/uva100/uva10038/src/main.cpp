// main file

#include <iostream>
#include <cmath>
#include <cstring>

int arr[3000];
bool mark[3001];

int main(int argc, char **argv) {
	int n = 0;
	while(scanf("%d", &n) == 1) {
		for(size_t i = 0; i < n; i++)
			scanf("%d", arr + i);
		memset(mark, 0, sizeof(mark));
		for(int i = 1; i < n; i++) mark[abs(arr[i] - arr[i - 1])] = 1;
		bool flag = false;
		for(size_t i = 1; i < n; i++) if (mark[i] == 0) flag = true;
		printf("%s\n", (flag ? "Not jolly" : "Jolly"));
	}
	return 0;
}