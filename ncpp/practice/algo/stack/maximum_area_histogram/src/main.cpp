// main file

#include <iostream>
#include <cstring>
#include <stack>

#define SZ (int)1e5 + 1

using ull = unsigned long long;
using stpi = std::stack<std::pair<int, int>>;

int input[SZ];
int nsl[SZ];
int nsr[SZ];

ull brute_force(int n) {
	ull max_area = 0;
	for(size_t i = 0; i < n; i++) {
		size_t width = 1;
		for(int j = i - 1; j >= 0; j--) {
			if(input[j] < input[i]) break;
			width += 1;
		}
		for(int j = i + 1; j < n; j++) {
			if(input[j] < input[i]) break;
			width += 1;
		}
		int area = width * input[i];
		max_area = std::max(max_area, (ull)area);
		//printf("debug: %zu, %lld\n", i, max_area);
	}
	return max_area;
}

/** basically you have to find index for "nearest smallest to left" and
 * "nearest smallest to right" */
ull with_stack(int n) {
	stpi st{};  /** pair<index, value> */
	ull max_area = 0;

	/** get nsl first */
	for(size_t i = 0; i < n; i++) {
		if(st.empty()) nsl[i] = -1;
		else if(input[i] <= st.top().second) {
			while(!st.empty() && input[i] <= st.top().second) st.pop();
			nsl[i] = st.empty() ? -1 : st.top().first;
		}
		else nsl[i] = st.top().first;
		st.push(std::make_pair(i, input[i]));
	}

	while(!st.empty()) st.pop();

	/** get nsr now */
	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) nsr[i] = n;
		else if(input[i] <= st.top().second) {
			while(!st.empty() && input[i] <= st.top().second) st.pop();
			nsr[i] = st.empty() ? n : st.top().first;
		}
		else nsr[i] = st.top().first;
		st.push(std::make_pair(i, input[i]));
	}


	/** for debugging use */
	//for(size_t i = 0; i < n; i++) {
		//printf("input: %d, nsl: %d, nsr: %d\n",
			//input[i], nsl[i], nsr[i]);
	//}

	for(int i = 0; i < n; i++) {
		ull area = (nsr[i] - nsl[i] - 1) * input[i];
		max_area = std::max(max_area, area);
	}
	return max_area;
}

int main(int argc, char **argv) {
	size_t T = 0, counter = 0;
	scanf("%zu", &T);
	while(T--) {
		memset(input, 0, sizeof(input));
		size_t n = 0;
		scanf("%zu", &n);
		for(size_t i = 0; i < n; i++) scanf("%d", input + i);
		ull res = with_stack(n);
		printf("Case: %zu ==> %lld\n", ++counter, res);
	}
	return 0;
}