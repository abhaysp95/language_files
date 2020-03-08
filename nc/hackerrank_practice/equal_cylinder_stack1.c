/** Name -> Abhay Shanker Pathak
Date -> 2020-03-07
Description -> Same as equal_cylinder_stack ques but with array
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-07*/
#include<stdio.h>
#define size 100

void push(int *, int );
void display(int *, int );
int total_of_arrele(int *, int );
int pop_stack(int *, int );
void rev_arr(int *, int );

int main(int argc, char *argv[]){
	int h1[size], h2[size], h3[size];
	int h1_count, h2_count, h3_count;
	int i = 0, j = 0, k = 0;
	int tota = 0, totb = 0, totc = 0;
	// push elements in stack
	printf("\nEnter count for first stack: ");
	scanf("%d", &h1_count);
	printf("\nEnter count for second stack: ");
	scanf("%d", &h2_count);
	printf("\nEnter count for third stack: ");
	scanf("%d", &h3_count);
	printf("\nPushing in first stack ");
	while (h1_count > 0) {
		push(h1, i);
		i++;
		h1_count--;
	}
	i--;
	printf("\nPushing in second stack ");
	while (h2_count > 0) {
		push(h2, j);
		j++;
		h2_count--;
	}
	j--;
	printf("\nPushing in third stack ");
	while (h3_count > 0) {
		push(h3, k);
		k++;
		h3_count--;
	}
	k--;

	// displaying the stack
	printf("\nDisplaying elements of first stack");
	display(h1, i);
	printf("\nDisplaying elements of second stack");
	display(h2, j);
	printf("\nDisplaying elements of third stack");
	display(h3, k);

	// reversing array
	rev_arr(h1, i);
	rev_arr(h2, j);
	rev_arr(h3, k);

	// get the total
	tota = total_of_arrele(h1, i);
	printf("\nSum of first stack: %d", tota);
	totb = total_of_arrele(h2, j);
	printf("\nSum of second stack: %d", totb);
	totc = total_of_arrele(h3, k);
	printf("\nSum of third stack: %d", totc);

	// logic for getting max and popping elements
	int c = 0;
	while (c == 0) {
		if (tota == totb) {
			if (totb == totc) {
				//printf("\nMaximum height of stack: %d", tota);
				c = 1;
			}
			else if (totb > totc) {
				i = pop_stack(h1, i);
				j = pop_stack(h2, j);
				//printf("\n Maximum height of stack: %d", totb);
			}
			else {
				k = pop_stack(h3, k);
				//printf("\n Maximum height of stack: %d", totc);
			}
		}
		else if (tota == totc) {
			if (totc > totb) {
				i = pop_stack(h1, i);
				k = pop_stack(h3, k);
				//printf("\nMaximum height of stack is: %d", totc);
			}
			else {
				j = pop_stack(h2, j);
				//printf("\nMaximum height of stack is: %d", totb);
			}
		}
		else if (totb == totc) {
			if (totc > tota) {
				j = pop_stack(h2, j);
				k = pop_stack(h3, k);
				//printf("\nMaximum height of stack is: %d", totc);
			}
			else {
				i = pop_stack(h1, i);
				//printf("\nMaximum height of stack is: %d", tota);
			}
		}
		else if (tota > totb) {
			if (tota > totc) {
				i = pop_stack(h1, i);
				//printf("\nMaximum height of stack is: %d", tota);
			}
			else {
				k = pop_stack(h3, k);
				//printf("\nMaximum height of stack is: %d", totc);
			}
		}
		else {
			if (totb > totc) {
				j = pop_stack(h2, j);
				//printf("\nMaximum height of stack is: %d", totb);
			}
			else {
				k = pop_stack(h3, k);
				//printf("\nMaximum height of stack is: %d", totc);
			}
		}
		/* n--; */
		tota = total_of_arrele(h1, i);
		//printf("\nSum of first stack: %d", tota);
		totb = total_of_arrele(h2, j);
		//printf("\nSum of second stack: %d", totb);
		totc = total_of_arrele(h3, k);
		//printf("\nSum of third stack: %d", totc);
	}
	printf("\nMaximum height of stack is: %d", tota);
	return 0;
}

void push(int *h1, int i) {
	//int val;
	if (i != size - 1) {
		printf("\nEnter data to push: ");
		scanf("%d", &h1[i]);
		//h1[i] = val;
	}
}

void display(int *h1, int i) {
	int m = 0;
	while (m <= i) {
		printf("\n%d", h1[m]);
		m++;
	}
}

int total_of_arrele(int *h1, int i) {
	int m = 0, sum = 0;
	while (m <= i) {
		sum += h1[m];
		m++;
	}
	return sum;
}

int pop_stack(int *h1, int i) {
	if (i >= 0) {
		i--;
	}
	return i;
}

void rev_arr(int *h1, int i) {
	int temp, m = 0;
	while (m <= i/2) {
		temp = h1[m];
		h1[m] = h1[i - m];
		h1[i - m] = temp;
		m++;
	}
}
