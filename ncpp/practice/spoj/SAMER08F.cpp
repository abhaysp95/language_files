#include <iostream>

int main(int argc, char** argv) {
	while(1) {
		int sl = 0;
		scanf("%d", &sl);
		if(sl == 0) break;
		int unsq = 0;
		for(int i = 1; i <= sl; i++) {
			unsq += (i * i);
		}
		printf("%d\n", unsq);
	}
	return 0;
}
