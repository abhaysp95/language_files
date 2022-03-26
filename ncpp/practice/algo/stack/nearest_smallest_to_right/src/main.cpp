// main file

#include <iostream>
#include <cstring>
#include <stack>

#define SZ (int)1e5 + 1

int arr[SZ];
int res[SZ];

void nearest_smallest_to_right(int n) {
	if (n < 1) return;
	std::stack<int> s{};
	for(int i = n - 1; i >= 0; i--) {
		if(s.empty()) res[i] = -1;
		else if(arr[i] <= s.top()) {
			while(!s.empty() && arr[i] <= s.top()) s.pop();
			res[i] = s.empty() ? -1 : s.top();
		}
		else res[i] = s.top();
		s.push(arr[i]);
	}
}

int main(int argc, char **argv) {
	int T = 0;
	scanf("%d", &T);
	while(T--) {
		memset(arr, 0, sizeof(arr));
		memset(res, -1, sizeof(res));
		int n = 0;
		scanf("%d", &n);
		for(size_t i = 0; i < n; i++) scanf("%d", arr + i);
		nearest_smallest_to_right(n);
		printf("%d", res[0]);
		for(size_t i = 1; i < n; i++) printf(" %d", res[i]);
		puts("");
	}
	return 0;
}