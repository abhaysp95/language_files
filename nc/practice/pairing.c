/** Name -> Abhay Shanker Pathak
Date -> 2020-03-30
Description -> Find the pairs
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-30 */

#include<stdio.h>
#include<stdlib.h>

int total_pair(int , int * );

// main function <<<
int main(int argc, char *argv[]){
	int *stock;
	int num, total;
	printf("\nEnter the num of total stock: ");
	scanf("%d", &num);

	printf("\nEnter the stock values: ");
	stock=malloc(sizeof(int) * num + 1);
	for (int i = 0; i < num; i++) {
		scanf("%d", (stock + i));
	}
	total=total_pair(num, stock);
	printf("\nTotal pair to sell is %d", total);
	return 0;
}
// >>>

// Function to get total pair <<<
int total_pair(int num, int *stock) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if (*(stock + i) > *(stock + j)) {
				*(stock + i) = *(stock + i) + *(stock + j);
				*(stock + j) = *(stock + i) - *(stock + j);
				*(stock + i) = *(stock + i) - *(stock + j);
			}
		}
	}

	// checking if loop worked or not
	for (int i = 0; i < num; i++) {
		printf("%d\n", *(stock + i));
	}


	int count = 1;
	int total = 0;
	for (int i = 0; i < num; i++) {
		count = 1;
		for (int j = i + 1; j < num; j++) {
			if (*(stock + i) == *(stock + j)) {
				count++;
			}
		}
		printf("count: %d", count);
		if (count > 1) {
			total = total + (count / 2);
		}
		i = i + (count - 1);
	}
	return total;
}
// >>>
