// main file

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int input_rows[9], rows[9], gcounter = 0, min_moves = 1e9;

void split(char *buf, char delim) {
	int counter = 0;
	char *token = strtok(buf, &delim);
	while(token != NULL) {
		sscanf(token, "%d", input_rows + ++counter);
		//printf("entered: %d\n", var);
		token = strtok(NULL, &delim);
	}
}

bool place(int col, int try_row) {
	for(int prev = 1; prev < col; prev++) {
		if(rows[prev] == try_row || (abs(rows[prev] - try_row) == abs(col - prev)))
			return false;
	}
	return true;
}

void backtrace(int col) {
	for(int try_row = 1; try_row <= 8; try_row++) {
		//if(place(col, input_rows[col])) {
			//rows[col] = input_rows[col];
			//backtrace(col + 1);
			//break;
		//}
		if(place(col, try_row)) {
			rows[col] = try_row;
			if(col == 8) {
				printf("%2d:\t", ++gcounter);
				for(int i = 1; i <= 8; i++) printf(" %d", rows[i]);
				puts("");
			}
			else {
				backtrace(col + 1);
				break;
			}
		}
	}
}

int main(int argc, char **argv) {
	char buf[256] = { '\0' };
	while(fgets(buf, sizeof buf, stdin)) {
		memset(rows, 0, sizeof rows);
		memset(input_rows, 0, sizeof input_rows);
		split(buf, ' ');  // put the input in array

		//printf("row entered: ");
		//for(int i = 1; i <= 8; i++) printf("%d ", *(rows + i));
		//puts("");

		backtrace(1);
	}
	return 0;
}