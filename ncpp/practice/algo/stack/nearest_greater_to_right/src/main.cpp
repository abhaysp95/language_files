// main file

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int arr[(int)1e5 + 1];
int res[(int)1e5 + 1];

void brute_force() {
	memset(arr, 0, sizeof arr);
	memset(res, 0, sizeof arr);
	int n = 0;
	scanf("%d", &n);
	for(size_t i = 0; i < n; i++) scanf("%d", arr + i);
	for(size_t i = 0; i < n; i++) {
		int mdiff = -1;
		for(size_t j = i + 1; j < n; j++) {
			if(arr[i] < arr[j]) {
				mdiff = arr[j];
				break;
			}
		}
		res[i] = mdiff;
	}
	printf("%d", res[0]);
	for(size_t i = 1; i < n; i++) printf(" %d", res[i]);
	puts("");
}

void using_stack() {
	memset(arr, 0, sizeof(arr));
	memset(res, 0, sizeof(res));
	int n = 0;
	scanf("%d", &n);
	for(size_t i = 0; i < n; i++) scanf("%d", arr + i);
	stack<int> s{};
	for(int i = n - 1; i >= 0; i--) {
		if(s.empty()) res[i] = -1;
		else if(arr[i] >= s.top()) {
			while(!s.empty() && arr[i] >= s.top()) s.pop();
			res[i] = s.empty() ? -1 : s.top();
		}
		else res[i] = s.top();
		s.push(arr[i]);
	}
	printf("%d", res[0]);
	for(size_t i = 1; i < n; i++) printf(" %d", res[i]);
	puts("");
}

int main(int argc, char **argv) {
	int T = 0;
	scanf("%d", &T);
	while(T--) {
		//brute_force();
		using_stack();
	}
	return 0;
}