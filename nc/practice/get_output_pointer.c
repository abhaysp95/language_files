/**
    _    ____  ____
   / \  / ___||  _ \   Abhay Shanker Pathak
  / _ \ \___ \| |_) |  abhaysp9955@gmail.com
 / ___ \ ___) |  __/   https://github.com/coolabhays
/_/   \_\____/|_|

get the output of following program */


#include<stdio.h>

// main function
int main(int argc, char* argv[]) {
	int arr[] = {0, 1, 2, 3, 4};
	int i, *p;
	for (p = arr, i = 0; p + i <= arr + 4; p++, i++) {
		printf("%d", *(p + i));
	}
	return 0;
}
