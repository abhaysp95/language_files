/** Name -> Abhay Shanker Pathak
Date -> 2020-03-10
Description -> Implementing stack operation according to given queries
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-10 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack {
	int data;
	struct stack *link;
} *root = NULL;

typedef struct stack stack;

stack *push(stack *);
stack *pop(stack *);
int max_display(stack *);

int main(int argc, char *argv[]){
	int ch, max_ele = 0, n;
	printf("\nEnter the total count of operation: ");
	scanf("%d", &n);

	while (n > 0) {
	printf("\n### QUERY MENU: ###");
	printf("\nEnter the choices for stack: ");
	printf("\n1. Push");
	printf("\n2. Pop");
	printf("\n3. Display max element");
	printf("\n4. EXIT");
	printf("\nEnter the choice: ");
	scanf("%d", &ch);

		switch (ch) {
			case 1: root = push(root);
					break;
			case 2: root = pop(root);
					break;
			case 3: max_ele = max_display(root);
					printf("\nMax element is: %d", max_ele);
					break;
			case 4:
					printf("\nExiting now");
			default:
					printf("\nWrong choice");
		}
		n--;
	}
	return 0;
}

stack *push(stack *root) {
	int val;
	printf("\nEnter the element: ");
	scanf("%d", &val);
	stack *temp = (stack *)malloc(sizeof(int));
	temp -> data = val;
	temp -> link = NULL;

	if (root == NULL)
		root = temp;
	else {
		temp -> link = root;
		root = temp;
	}
	return root;
}

stack *pop(stack *root) {
	stack *ptr;
	ptr = root;
	if (ptr == NULL)
		printf("\nUNDERFLOW");
	else {
		root = root -> link;
		free(ptr);
	}
	return root;
}

int max_display(stack *root) {
	stack *ptr;
	int max;
	ptr = root;
	max = ptr -> data;
	while (ptr != NULL) {
		if (max < ptr -> data)
			max = ptr -> data;
		ptr = ptr -> link;
	}
	return max;
}
