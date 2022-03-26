// main file

#include <iostream>
#include <cstring>
#include <stack>

#define SZ (int)1e5 + 1

int mah[SZ];
int res[SZ];

using ull = unsigned long long;
using mpair =  std::pair<int, int>;

ull do_mah(size_t col) {
	std::stack<mpair> st{};  // pair<index, value>

	// get nsl first
	for(size_t i = 0; i < col; i++) {
		if(st.empty()) res[i] = -1;
		else if(mah[i] <= st.top().second) {
			while(!st.empty() && mah[i] <= st.top().second) st.pop();
			res[i] = st.empty() ? -1 : st.top().first;
		}
		else res[i] = st.top().first;
		st.push(std::make_pair(i, mah[i]));
	}

	while(!st.empty()) st.pop();

	// get nsr and then get max area
	size_t tidx = 0;
	for(int i = col - 1; i >= 0; i--) {
		if(st.empty()) tidx = col;
		else if(mah[i] <= st.top().second) {
			while(!st.empty() && mah[i] <= st.top().second) st.pop();
			tidx = st.empty() ? col : st.top().first;
		}
		else tidx = st.top().first;
		st.push(std::make_pair(i, mah[i]));
		res[i] = tidx - res[i] - 1;
	}

	ull max_area = 0;
	for(size_t i = 0; i < col; i++)
		max_area = std::max(max_area, (ull)mah[i] * res[i]);

	return max_area;
}

int main(int argc, char **argv) {
	int T = 0;
	scanf("%d", &T);
	while(T--) {
		size_t row = 0, col = 0;
		scanf("%zu %zu", &row, &col);
		memset(mah, 0, sizeof(mah));
		ull res = 0;

		for(size_t i = 0; i < row; i++) {
			if(!i) for(size_t j = 0; j < col; j++) scanf("%d", mah + j);
			else {
				int val = 0;
				for(size_t j = 0; j < col; j++) {
					scanf("%d", &val);
					mah[j] = !val ? 0 : mah[j] + val;
				}
			}

			ull temp_res = do_mah(col);
			res = std::max(res, do_mah(col));

			/** for debuggging use */
			printf("row: %zu, mah:\n\t%d", i + 1, mah[0]);
			for(size_t j = 1; j < col; j++) printf(" %d", mah[j]);

			printf("\tmah: %lld\n", temp_res);
		}
		printf("max area rectangle in binary matrix: %lld\n", res);
	}
	return 0;
}