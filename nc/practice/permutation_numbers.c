/** Name -> Abhay Shanker Pathak
Date -> 2020-03-12
Description -> Permutations of numbers
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-12 */

#include<stdio.h>
#include<stdlib.h>

void permute(int * ,int ,int ,int  );
void swap(int * , int *);
int factorial(int );
void sort_removedup(int *, int );

struct new {
	int a, b, c;
	struct new *link;
};

int main(int argc, char *argv[]){
	int n, *num;
	printf("\nEnter the count for numbers: ");
	scanf("%d", &n);
	printf("\nEnter the numbers: ");
	num = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("%d: ", i + 1);
		scanf("%d", num + i);
	}
	int fact;
	fact = factorial(n);
	/* printf("\nFactorial is %d", fact); */
	permute(num, 0, n - 1, fact);
	sort_removedup(num, n);
	return 0;
}

void permute(int *num, int l, int p, int fact) {
	struct new *temp = (struct new *)malloc(fact * sizeof(int));
	if (l == p) {
		printf("\n");
		for (int i = 0; i <=p; i++) {
			printf("%d", *(num + i));
			temp->a = *(num + i);
			i++;
			temp->b = *(num + i);
			i++;
			temp->c = *(num + i);
			/* temp = temp -> link; */
		}
	}
		/* printf("\n%d", *num); */
	else {
		for (int i = l; i <= p; i++) {
			swap((num + l), (num + i));
			permute(num, l + 1, p, fact);
			swap((num + l), (num + i));
		}
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int factorial(int f) {
	if (f >= 1)
		return f * factorial(f - 1);
	else
		return 1;
}

void sort_removedup(int *num, int l) {
	int i, j;
	for (i = 0; i < l - 1; i++) {
		for (j = 0; j < l - i -1; j++) {
			if (*(num + j) > *(num + (j + 1))) {
				int temp = *(num + j);
				*(num + j) = *(num + (j + 1));
				*(num + (j + 1)) = temp;
			}
		}
	}
	for (i = 0; i < l; i++) {
		/* printf("%d", *(num + i)); */
		if (*(num + i) == *(num + (i + 1)))
			i++;
	}
}

// not complete, trying to remove duplicacy, rest works fine
