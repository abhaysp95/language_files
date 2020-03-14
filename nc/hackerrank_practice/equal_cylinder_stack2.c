/** Name -> Abhay Shanker Pathak
Date -> 2020-03-07
Description -> Height of stack should be equal for each cylinder with linked list
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-07 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
} *root1 = NULL, *root2 = NULL, *root3 = NULL;

struct node *push_stack(struct node *);
struct node *display(struct node *);
int pop_stack1(struct node *);
int pop_stack2(struct node *);
int pop_stack3(struct node *);
void freethelist(struct node *);
int total_of_llele(struct node *);

int main(int argc, char *argv[]){
	int n1, n2, n3, tota, totb, totc, a, b, c;
	printf("\nEnter the element number for first stack cylinder: ");
	scanf("%d", &n1);
	printf("\nEnter the element number for second stack cylinder: ");
	scanf("%d", &n2);
	printf("\nEnter the element number for third stack cylinder: ");
	scanf("%d", &n3);
	// insertion in first stack
	while (n1 > 0) {
		printf("\nElement in first stack: ");
		root1 = push_stack(root1);
		n1--;
	}
	// insertion in second stack
	while (n2 > 0) {
		printf("\nElement in second stack: ");
		root2 = push_stack(root2);
		n2--;
	}
	// insertion in third stack
	while (n3 > 0) {
		printf("\nElement in third stack: ");
		root3 = push_stack(root3);
		n3--;
	}
	// displaying first stack
	printf("\nElements of first stack: ");
	root1 = display(root1);
	// displaying second stack
	printf("\nElements of second stack: ");
	root2 = display(root2);
	// displaying third stack
	printf("\nElements of third stack: ");
	root3 = display(root3);

	/* The logic here is get total of stack at every instance and then comparing */
	/* 	and then popping out */
	tota = total_of_llele(root1);
	//printf("\nTotal from first stack: %d", tota);
	totb = total_of_llele(root2);
	//printf("\nTotal from second stack: %d", totb);
	totc = total_of_llele(root3);
	//printf("\nTotal from third stack: %d", totc);

	// comparision logic
	/* while (tota != totb || totb != totc || tota != 0 || totb != 0 || totc != 0) { */
	int d = 0;
	while (d == 0) {
		if (tota == totb) {
			if (totb == totc) {
				//printf("\nMaximum height of stack: %d", tota);
				d = 1;
			}
			else if (totb > totc) {
				a = pop_stack1(root1);
				tota -= a;
				b = pop_stack2(root2);
				totb -= b;
				//printf("\n Maximum height of stack: %d", totb);
			}
			else {
				c = pop_stack3(root3);
				totc -= c;
				//printf("\n Maximum height of stack: %d", totc);
			}
		}
		else if (tota == totc) {
			if (totc > totb) {
				a = pop_stack1(root1);
				tota -= a;
				c = pop_stack3(root3);
				totc -= c;
				//printf("\nMaximum height of stack is: %d", totc);
			}
			else {
				b = pop_stack2(root2);
				totb -= b;
				//printf("\nMaximum height of stack is: %d", totb);
			}
		}
		else if (totb == totc) {
			if (totc > tota) {
				b = pop_stack2(root2);
				totb -= b;
				c = pop_stack3(root3);
				totc -= c;
				//printf("\nMaximum height of stack is: %d", totc);
			}
			else {
				a = pop_stack1(root1);
				tota -= a;
				//printf("\nMaximum height of stack is: %d", tota);
			}
		}
		else if (tota > totb) {
			if (tota > totc) {
				a = pop_stack1(root1);
				tota -= a;
				//printf("\nMaximum height of stack is: %d", tota);
			}
			else {
				c = pop_stack3(root3);
				totc -= c;
				//printf("\nMaximum height of stack is: %d", totc);
			}
		}
		else {
			if (totb > totc) {
				b = pop_stack2(root2);
				totb -= b;
				//printf("\nMaximum height of stack is: %d", totb);
			}
			else {
				c = pop_stack3(root3);
				totc -= c;
				//printf("\nMaximum height of stack is: %d", totc);
			}
		}
		/* n--; */
	/* tota = total_of_llele(root1); */
	//printf("\nTotal from first stack: %d", tota);
	/* totb = total_of_llele(root2); */
	//printf("\nTotal from second stack: %d", totb);
	/* totc = total_of_llele(root3); */
	//printf("\nTotal from third stack: %d", totc);
	}
	printf("\nSo, total max height of stack will be: %d", tota);

	// freeing the stack(linked list)
	freethelist(root1);
	freethelist(root2);
	freethelist(root3);
	return 0;
}

struct node *push_stack(struct node *root) {
	struct node *temp, *ptr;
	int val;
	scanf("%d", &val);
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = val;
	temp -> link = NULL;
	if (root == NULL)
		root = temp;
	else {
		ptr = root;
		while (ptr -> link != NULL)
			ptr = ptr -> link;
		ptr -> link = temp;
	}
	return root;
}

struct node *display(struct node *root) {
	struct node *ptr;
	ptr = root;
	while (ptr != NULL) {
		printf("%d\n", ptr -> data);
		ptr = ptr -> link;
	}
	return root;
}

int total_of_llele(struct node *root) {
	struct node *ptr;
	ptr = root;
	int sum = 0;
	while (ptr != NULL) {
		sum += ptr -> data;
		ptr = ptr -> link;
	}
	return sum;
}

int pop_stack1(struct node *root1) {
	struct node *ptr;
	int a;
	ptr = root1;
	if (ptr != NULL) {
		a = root1 -> data;
		root1 = root1 -> link;
		free(ptr);
	}
	return a;
}

int pop_stack2(struct node *root2) {
	struct node *ptr;
	int b;
	ptr = root2;
	if (ptr != NULL) {
		b = root2 -> data;
		root2 = root2 -> link;
		free(ptr);
	}
	return b;
}

int pop_stack3(struct node *root3) {
	struct node *ptr;
	int c;
	ptr = root3;
	if (ptr != NULL) {
		c = root1 -> data;
		root3 = root3 -> link;
		free(ptr);
	}
	return c;
}

void freethelist(struct node *root) {
	while (root != NULL) {
		struct node *temp = root;
		root = root -> link;
		free(temp);
	}
}
