// main file

#include <iostream>
#include <cstring>
#include <stack>

#define SZ (int)1e5 + 1

int arr[SZ];
int res[SZ];

/** The solution uses the concept of NGL, you can get different variations for
 * the problem using NGR, NSL and NSR */

void stock_span(int n) {
	std::stack<int> s{};
	for(size_t i = 0; i < n; i++) {
		size_t counter = 1;
		if(s.empty()) res[i] = counter;
		else if(arr[i] < s.top()) res[i] = counter;
		else {
			std::stack<int> t{};
			while(!s.empty() && arr[i] >= s.top()) {
				t.push(s.top());
				s.pop();
				counter++;
			}
			while(!t.empty()) s.push(t.top()), t.pop();
			res[i] = counter;
		}
		s.push(arr[i]);
	}
}

void stock_span2(int n) {
	if (n < 1) return;
	std::stack<std::pair<int, int>> s{};  // pair<val, idx>
	for(size_t i = 0; i < n; i++) {
		if (s.empty()) res[i] = 1;
		else if(arr[i] < s.top().first) res[i] = 1;
		else {
			while(!s.empty() && arr[i] >= s.top().first) s.pop();
			res[i] = s.empty() ? i + 1 : i - s.top().second;
		}
		s.push(std::make_pair(arr[i], i));
	}
}

int main(int argc, char **argv) {
	int T = 0;
	scanf("%d", &T);
	while(T--) {
		memset(arr, 0, sizeof(arr));
		memset(res, 0, sizeof(res));
		int n = 0;
		scanf("%d", &n);
		for(size_t i = 0; i < n; i++) scanf("%d", arr + i);
		stock_span2(n);
		printf("%d", res[0]);
		for(size_t i = 1; i < n; i++) printf(" %d", res[i]);
		puts("");
	}
	return 0;
}