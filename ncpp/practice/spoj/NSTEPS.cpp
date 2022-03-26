#include <iostream>

int main(int argc, char **argv) {
	int t = 0;
	scanf("%d", &t);
	while(t--) {
		int x = 0, y = 0;
		scanf("%d %d", &x, &y);
		if((y > x) || (x - y == 1) || (x -y >= 3))
			printf("No Number\n");
		else {
			int start = 0;
			if(x > y) start = 2;
			for(int i = (x > y ? 2 : 0); i < x; i++) {
				if(i % 2 == 0) start += 1;
				else start += 3;
			}
			printf("%d\n", start);
		}
	}
	return 0;
}
