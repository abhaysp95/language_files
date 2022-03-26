#include <iostream>
#include <algorithm>

// place each cow at distance of mid and if all cows are placed then it is one
// of the possible solutions
bool check_pos(int* arr, int mid, int n, int c) {
	int ccount = 1, pos = arr[0];
	for(int i = 1; i < n; i++) {
		if(arr[i] - pos >= mid) {
			pos = arr[i];
			ccount++;
		}
		if(ccount == c) return 1;
	}
	return 0;
}

int bin_search(int* arr, int n, int c) {
	std::sort(arr, arr + n);
	//printf("after sort:\n");
	//for(int i = 0; i < n; i++) printf("%d\n", arr[i]);
	int low = arr[0], high = arr[n - 1], min_diff = -1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		//printf("mid: %d\n", mid);
		if(check_pos(arr, mid, n, c)) {
			low = mid + 1;
			min_diff = mid;
			//printf("min_diff: %d\n", min_diff);
		}
		else high = mid - 1;
	}
	return min_diff;
}

int main(int argc, char** argv) {
	int t = 0;
	scanf("%d", &t);
	while(t--) {
		int n = 0, c = 0;
		scanf("%d %d", &n, &c);
		int arr[n];
		for(int i = 0; i < n; i++) scanf("%d", arr + i);
		int largest_min_dist = bin_search(arr, n, c);
		printf("%d\n", largest_min_dist);
	}
}
