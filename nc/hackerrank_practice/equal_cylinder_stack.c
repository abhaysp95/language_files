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
struct node *pop_stack(struct node *);
void freethelist(struct node *);
int total_of_llele(struct node *);

int main(int argc, char *argv[]){
	int n1, n2, n3, tota, totb, totc;
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
	int c = 0;
	while (c == 0) {
		if (tota == totb) {
			if (totb == totc) {
				//printf("\nMaximum height of stack: %d", tota);
				c = 1;
			}
			else if (totb > totc) {
				root1 = pop_stack(root1);
				root2 = pop_stack(root2);
				//printf("\n Maximum height of stack: %d", totb);
			}
			else {
				root3 = pop_stack(root3);
				//printf("\n Maximum height of stack: %d", totc);
			}
		}
		else if (tota == totc) {
			if (totc > totb) {
				root1 = pop_stack(root1);
				root3 = pop_stack(root3);
				//printf("\nMaximum height of stack is: %d", totc);
			}
			else {
				root2 = pop_stack(root2);
				//printf("\nMaximum height of stack is: %d", totb);
			}
		}
		else if (totb == totc) {
			if (totc > tota) {
				root2 = pop_stack(root2);
				root3 = pop_stack(root3);
				//printf("\nMaximum height of stack is: %d", totc);
			}
			else {
				root1 = pop_stack(root1);
				//printf("\nMaximum height of stack is: %d", tota);
			}
		}
		else if (tota > totb) {
			if (tota > totc) {
				root1 = pop_stack(root1);
				//printf("\nMaximum height of stack is: %d", tota);
			}
			else {
				root3 = pop_stack(root3);
				//printf("\nMaximum height of stack is: %d", totc);
			}
		}
		else {
			if (totb > totc) {
				root2 = pop_stack(root2);
				//printf("\nMaximum height of stack is: %d", totb);
			}
			else {
				root3 = pop_stack(root3);
				//printf("\nMaximum height of stack is: %d", totc);
			}
		}
		/* n--; */
	tota = total_of_llele(root1);
	//printf("\nTotal from first stack: %d", tota);
	totb = total_of_llele(root2);
	//printf("\nTotal from second stack: %d", totb);
	totc = total_of_llele(root3);
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

struct node *pop_stack(struct node *root) {
	struct node *ptr;
	ptr = root;
	if (ptr != NULL) {
		root = root -> link;
		free(ptr);
	}
	return root;
}

void freethelist(struct node *root) {
	while (root != NULL) {
		struct node *temp = root;
		root = root -> link;
		free(temp);
	}
}
