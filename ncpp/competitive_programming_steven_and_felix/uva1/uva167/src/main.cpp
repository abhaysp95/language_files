// main file

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int mat[9][9], row[9], track_counter = 0;

bool place(int col, int try_row) {
	for(int prev = 1; prev < col; prev++)
		if(row[prev] == try_row || (abs(row[prev] - try_row) == abs(col - prev)))
			return false;
	return true;
}

void backtrack(int col, int *max_sum) {
	for(int try_row = 1; try_row <= 8; try_row++) {
		if(place(col, try_row)) {
			row[col] = try_row;
			if(col == 8) {
				//printf("%2d\t%d", ++track_counter, row[1]);
				//for(int j = 2; j <= 8; j++) printf(" %2d", row[j]);
				//puts("");
				int temp_sum = 0;
				for(int i = 1; i <= 8; i++) temp_sum += mat[row[i]][i];
				*max_sum = (*max_sum > temp_sum ? *max_sum : temp_sum);
			}
			else backtrack(col + 1, max_sum);
		}
	}
}

int main(int argc, char **argv) {
	int TC = 0;
	scanf("%d", &TC);
	while(TC--) {
		memset(mat, 0, sizeof mat);
		memset(row, 0, sizeof row);
		for(int i = 1; i <= 8; i++)
			for(int j = 1; j <= 8; j++) scanf("%d", &mat[i][j]);
		int res = 0;
		backtrack(1, &res);
		printf("max_sum: %5d\n", res);
	}
	return 0;
}