// main file

#include <stdio.h>
#include <string.h>

void swap(char* a, char* b);
void permute_string(char* str, int start, int end);

void swap(char* a, char* b) {
	printf("Swap a = %c, b = %c\n", *a, *b);
	if (*a != *b) {
		char temp = *a;
		*a = *b;
		*b = temp;
	}
}

void permute_string(char* str, int start, int end) {
	if (start == end) {
		printf("%s\n", str);
	}
	else {
		for (int index = start; index <= end; ++index) {
			printf("got index = %d, start = %d\n", index, start);
			printf("above first swap\n");
			swap((str + start), (str + index));
			permute_string(str, start+1, end);
			printf("above second swap\n");
			swap((str + start), (str + index));  // backtracking
			// backtracking here simply mean that, whatever the first swap is making change reverse that change after printing or storing
			printf("end of a iteration\n");
		}
	}
}

int main(int argc, char **argv) {
	/*char* new_str = "abc";*/  // the "abc" is in the read-only memory and new_str is just pointer to that read-only memory
	// so if you try to modify this string you'll get segfault
	char new_str[] = "abc";  // this is in modifiable stack
	int n = strlen(new_str);
	permute_string(new_str, 0, n-1);
    return 0;
}