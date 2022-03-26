// main file

#include <iostream>
#include <cstring>
#include <stack>

#define SZ (int)1e5 + 1

int input[SZ];
int res[SZ];

using stp = std::stack<std::pair<int, int>>;
using ull = unsigned long long;

ull perform_mah(size_t n) {
	stp st{};

	/** get ngl */
	for(size_t i = 0; i < n; i++) {
		if(st.empty()) res[i] = -1;
		else if(input[i] > st.top().second) {
			while(!st.empty() && input[i] > st.top().second) st.pop();
			res[i] = st.empty() ? -1 : st.top().first;
		}
		else res[i] = st.top().first;
		st.push(std::make_pair(i, input[i]));
	}

	while(!st.empty()) st.pop();

	/** get ngr and perform other operations */
	int tmp_idx = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) tmp_idx = -1;
		else if(input[i] > st.top().second) {
			while(!st.empty() && input[i] > st.top().second) st.pop();
			tmp_idx = st.empty() ? -1 : st.top().first;
		}
		else tmp_idx = st.top().first;
		st.push(std::make_pair(i, input[i]));

		/** update res */
		if(res[i] == -1 || tmp_idx == -1) res[i] = 0;
		else {
			/** problem starts from here, that's why this method (one similar
			 * to histogram is not being used) */
		}
	}
	return 0;
}

int main(int argc, char **argv) {
	int T = 0;
	scanf("%d", &T);
	while(T--) {
		size_t n = 0;
		scanf("%zu", &n);
		for(size_t i = 0; i < n; i++) scanf("%d", input + i);
		perform_mah(n);
	}
	return 0;
}