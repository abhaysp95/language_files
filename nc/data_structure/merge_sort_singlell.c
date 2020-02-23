/** Name -> Abhay Shanker Pathak
Date -> 2020-02-23
Description -> Merge and sort two singly linked list
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-23 */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
} *root = NULL, *root2 = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *merge(struct node *, struct node * );

int main(int argc, char *argv[]){
	root = create_ll(root);
	root2 = create_ll(root2);
	root = merge(root, root2);
	return 0;
}


struct node *create_ll(struct node *root) {
	struct node *temp, *ptr;
	int val, num;
	printf("\nEnter the limit: ");
	scanf("%d", &val);
	while (val > 0) {
		printf("\nEnter the element\n(-1) to cancel: ");
		scanf("%d", &num);
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> data = num;
		temp -> link = NULL;
		if (root == NULL)
			root = temp;
		else {
			ptr = root;
			while (ptr -> link != NULL)
				ptr = ptr -> link;
			ptr -> link = temp;
		}
		val--;
	}
	root = display(root);
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

struct node *merge(struct node *root, struct node *root2) {
	struct node *temp, *ptr, *preptr = NULL, *pptr;
	ptr = root;
	//preptr = ptr;
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = ptr -> data;
	ptr = root -> link;
	preptr = temp;
	pptr = preptr;
	while (ptr != NULL) {
		while (pptr != NULL) {
			pptr = pptr -> link;
		}
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> data = ptr -> data;
		temp -> link = NULL;
		pptr -> link = temp;
		ptr = ptr -> link;
	}
	ptr = root2;
	while (ptr != NULL) {
		while (pptr != NULL) {
			pptr = pptr -> link;
		}
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> data = ptr -> data;
		temp -> link = NULL;
		pptr -> link = temp;
		ptr = ptr -> link;
	}
	preptr = display(preptr);
	return preptr;
}
