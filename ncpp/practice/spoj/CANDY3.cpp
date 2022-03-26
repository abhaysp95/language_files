#include <iostream>

int main(int argc, char** argv) {
	int t = 0;
	scanf("%d", &t);
	while(t--) {
		fgetc(stdin);
		int N = 0;
		scanf("%d", &N);
		int sum = 0;
		for(int i = 0; i < N; i++) {
			int temp = 0;
			scanf("%d", &temp);
			sum += temp;
		}
		printf("%s\n", (sum % N == 0) ? "YES" : "NO");
	}
	return 0;
}
