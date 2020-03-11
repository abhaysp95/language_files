/** Name -> Abhay Shanker Pathak
Date -> 2020-03-11
Description -> Implementing queue operations with stack
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> date */

#include<stdio.h>
#include<stdlib.h>

struct stq {
	int data;
	struct stq *link;
} *root1 = NULL, *root2 = NULL;

struct stq *enque(struct stq * ,int );
void deque(struct stq * ,struct stq *);
int display_front(struct stq *);

int main(int argc, char *argv[]){
	int ch, n, val, front;
	printf("\nEnter the count of operations: ");
	scanf("%d", &n);
	while (n > 0) {
		printf("\n### Main Menu ###");
		printf("\n1. Enque");
		printf("\n2. Deque");
		printf("\n3. Element at front of queue");
		printf("\n4. EXIT");
		printf("\nEnter the choice: ");
		scanf("%d", &ch);

		switch (ch) {
			case 1:
				printf("\nEnter the elements value: ");
				scanf("%d", &val);
				root1 = enque(root1, val);
				break;
			case 2:
				deque(root1, root2);
				break;
			case 3:
				front = display_front(root1);
				printf("\nFront element is: %d", front);
				break;
			case 4:
				printf("\nExiting now!");
				break;
			default:
				printf("\nWrong choice");
		}
		n--;
	}
	return 0;
}

struct stq *enque(struct stq *root1, int val) {
	struct stq *temp = (struct stq *)malloc(sizeof(struct stq));
	temp -> data = val;
	temp -> link = NULL;
	if (root1 == NULL)
		root1 = temp;
	else {
		temp -> link = root1;
		root1 = temp;
	}
	return root1;
}

void deque(struct stq *root1, struct stq *root2) {
	struct stq *ptr, *pptr;
	ptr = root1;
	if (ptr != NULL) {
		while (ptr -> link -> link != NULL) {
			root2 = enque(root2, ptr -> data);
			pptr = ptr;
			ptr = ptr -> link;
			free(pptr);
		}
		while (ptr -> link != NULL) {
			pptr = ptr;
			ptr = ptr -> link;
			free(pptr);
		}
		free(ptr);
	}

	if (root2 != NULL) {
		ptr = root2;
		while (ptr -> link != NULL) {
			root1 = enque(root1, ptr -> data);
			ptr = ptr -> link;
		}
	}
}

int display_front(struct stq *root1) {
	struct stq *ptr;
	ptr = root1;
	if (ptr != NULL) {
		while (ptr -> link != NULL)
			ptr = ptr -> link;
	}
	return ptr -> data;
}
