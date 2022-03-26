// main file

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int row[9], a = 0, b = 0, line_counter = 0;

bool place(int col, int tryrow) {
	for(int prev = 1; prev < col; prev++) {  // check previously placed queens
		if(row[prev] == tryrow || abs(row[prev] - tryrow) == abs(prev - col))
			return false;
	}
	return true;
}

void backtrack(int col) {
	for(int tryrow = 1; tryrow <= 8; tryrow++) {  // try all possible rows
		if(col > b && row[b] != a) break;  // no need to go through the path which doesn't satisfies the constraint
		if(place(col, tryrow)) {  // if can place the queen at 'tryrow' row nad 'col' column
			row[col] = tryrow;  // place the queen
			if(col == 8 && row[b] == a) {  // if queen in row 'a' of col 'b'
				printf("%2d\t%d", ++line_counter, row[1]);
				for(int j = 2; j <= 8; j++) printf(" %d", row[j]);
				puts("");  // try queen in next
			}
			else backtrack(col + 1);  // try next column recursively
		}
	}
}

int main(int argc, char **argv) {
	int TC = 0;
	scanf("%d", &TC);
	while(TC--) {
		scanf("%d %d", &a, &b);
		memset(row, 0, sizeof row);
		printf("SOLN\tCOLUMN\n");
		printf(" #\t1 2 3 4 5 6 7 8\n\n");
		backtrack(1);
		if(TC) puts("");
	}
	return 0;
}