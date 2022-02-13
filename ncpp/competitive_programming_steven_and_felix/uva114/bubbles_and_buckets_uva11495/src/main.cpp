// main file

#include <iostream>

int main(int argc, char **argv) {
	int len = 0;
	while(scanf("%d", &len)) {
		if(len == 0) break;
		int arr[len];
		int prbk = 1;
		int chances = 0;
		for(int i = 0; i < len; i++) scanf("%d", arr + i);
		while(prbk) {
			prbk = 0;
			for(int i = 1; i < len; i++) {
				if(arr[i] < arr[i - 1]) {
					arr[i] += arr[i - 1];
					arr[i - 1] = arr[i] - arr[i - 1];
					arr[i] = arr[i] - arr[i - 1];
					chances++;
					prbk = 1;
				}
			}
		}
		printf("%s\n", (chances % 2 == 0) ? "Carlos" : "Marcelo");
	}
	return 0;
}