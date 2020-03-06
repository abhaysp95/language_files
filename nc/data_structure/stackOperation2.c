/** Name -> Abhay Shanker Pathak
Date -> 2020-03-02
Description -> Stack Operations using linked list
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-02 */

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
	int data;
	struct node *link;
} *top=NULL;

struct node *push(struct node *, int );
struct node *pop(struct node *);
int peek(struct node *);
struct node *display(struct node *);

int main(int argc, char *argv[]){
	int val, choice;
	do {
		printf("## Menu ##");
		printf("\n 1. Push ");
		printf("\n 2. Pop");
		printf("\n 3. Peek");
		printf("\n 4. Display");
		printf("\n 5. Exit");
		printf("\n Enter your option: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\n Enter the number to push in stack: ");
				scanf("%d", &val);
				top = push(top, val);
				break;
			case 2:
				top = pop(top);
				break;
			case 3:
				val = peek(top);
				if (val != -1)
					printf("\n Top value of stack is %d", val);
				else
					printf("\nStack is empty");
				break;
			case 4:
				top = display(top);
				break;
		}
	} while (choice != 5);
	return 0;
}

struct node *push(struct node *top, int val) {
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr -> data = val;
	if (top == NULL) {
		ptr -> link = NULL;
		top = ptr;
	}
	else {
		ptr -> link = top;
		top = ptr;
	}
	return top;
}

int peek(struct node *top) {
	if(top == NULL)
		return -1;
	else
		return top -> data;
}

struct node *display(struct node *top) {
	struct node *ptr;
	ptr = top;
	if(top == NULL)
		printf("\nStack is empty");
	else{
		while (ptr != NULL)
		{
			printf("\n %d", ptr -> data);
			ptr = ptr -> link;
		}
	}
	return top;
}

struct node *pop(struct node *top) {
	struct node *ptr;
	ptr = top;
	if (top == NULL)
		printf("\nStack Underflow");
	else {
		top = top -> link;
		printf("\n Value popped from stack: %d", ptr -> data);
		free(ptr);
	}
	return top;
}
