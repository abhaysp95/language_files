/** Name -> Abhay Shanker Pathak
Date -> 2020-02-20
Description -> Remove maximux element from linked list
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-20 */

#include<stdio.h>
#include<stdlib.h>
#define size 1000

struct node {
	int data;
	struct node *link;
} *root = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *max_del(struct node *);

int main(int argc, char *argv[]){
	// creation of linked list
	root = create_ll(root);
	// finding max element and deleting it
	/* root = max_del(root); */
	/* // display list */
	// display list
	/* root = display(root); */
	return 0;
}

struct node *create_ll(struct node *root) {
	struct node *ptr, *temp;
	int val, num;
	printf("\nEnter the limit: ");
	scanf("%d", &val);
	/* if (val >= 1 && val <= 10) { */
		while (val > 0) {
				printf("\nEnter the element: ");
				scanf("%d", &num);
				temp = (struct node *)malloc(sizeof(struct node));
				temp -> data = num;
				temp -> link = NULL;
				if (root == NULL) {
					root = temp;
				}
				else {
					ptr = root;
					while (ptr -> link != NULL) {
						ptr = ptr -> link;
					}
					ptr -> link = temp;
					temp -> link = NULL;
				}
				root = max_del(root);
			}
			val--;
		}
	root = max_del(root);
	root = display(root);
	}
	else {
		while (val > 0) {
			int i = 0;
			scanf("%d", &arr[i]);
			val--;
			i++;
		}
	/* } */
	/* else { */
	/* 	for (int i = 0; i < val; i++) */
	/* 		scanf("%d", &arr[i]); */
	/* 	printf("\nfriend list exceeded from limit"); */
	/* } */
	return root;
}

struct node *max_del(struct node *root) {
	int max = 0;
	struct node *ptr, *preptr;
	ptr = root;
	max = ptr -> data;
	while (ptr -> link != NULL) {
		ptr = ptr -> link;
		if (max < ptr -> data) {
			max = ptr -> data;
		}
	}
	printf("\nMax element is %d", max);
	ptr = root;
	if (ptr -> data == max) {
		root = root -> link;
	}
	else {
		while (ptr -> data != max) {
			preptr = ptr;
			ptr = ptr -> link;
		}
		preptr -> link = ptr -> link;
	}
	root = display(root);
		free(ptr);
	return root;
}

struct node *display(struct node *root) {
	struct node *ptr;
	ptr = root;
	printf("\nList is: ");
	while (ptr != NULL) {
		printf("\n%d", ptr -> data);
		ptr = ptr -> link;
	}
	return root;
}
