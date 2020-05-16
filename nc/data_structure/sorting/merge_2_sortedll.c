/** Name -> Abhay Shanker Pathak
Date -> 2020-02-26
Description -> Merge two sorted linked list
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-26 */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
} *root=NULL, *root2=NULL, *tmp=NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *sorting(struct node *);
struct node *merge(struct node *, struct node *);

int main(int argc, char *argv[]){
	printf("\nCreation of First linked list: ");
	root = create_ll(root);
	printf("\nCreation of Second linked list: ");
	root2 = create_ll(root2);
	printf("\nSorting First linked list: ");
	root = sorting(root);
	printf("\nSorting Second linked list: ");
	root2 = sorting(root2);
	printf("\nMerging those two sorted linked list: ");
	tmp = merge(root, root2);
	return 0;
}

struct node *create_ll(struct node *root) {
	struct node *ptr, *temp;
	int val, num;
	printf("\nEnter the element count: ");
	scanf("%d", &num);
	while (num > 0) {
		printf("\nEnter the value: ");
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
		num--;
	}
	root = display(root);
	return root;
}

struct node *display(struct node *root) {
	struct node *ptr;
	ptr = root;
	printf("\nEntered elements are: ");
	while (ptr != NULL) {
		printf("\n%d", ptr -> data);
		ptr = ptr -> link;
	}
	return root;
}

struct node *sorting(struct node *root) {
	struct node *ptr, *preptr;
	int temp;
	ptr = root;
	while (ptr != NULL) {
		preptr = ptr -> link;
		while (preptr != NULL) {
			if (ptr -> data > preptr -> data) {
				temp = ptr -> data;
				ptr -> data = preptr -> data;
				preptr -> data = temp;
			}
			preptr = preptr -> link;
		}
		ptr = ptr -> link;
	}
	root = display(root);
	return root;
}

struct node *merge(struct node *root, struct node *root2) {
	struct node *sort_head, *root3 = NULL, *ptr, *pptr;
	ptr = root;
	pptr = root2;
	if (root == NULL)
		return root2;
	if (root2 == NULL)
		return root;
	// if both roots are present
	if (ptr && pptr) {
		if (ptr -> data <= pptr -> data) {
			sort_head = ptr;
			ptr = sort_head -> link;
		}
		else {
			sort_head = pptr;
			pptr = sort_head -> link;
		}
	}
	root3 = sort_head;
	while (ptr && pptr) {
		if (ptr -> data <= pptr -> data) {
			sort_head -> link = ptr;
			sort_head = ptr;
			ptr = sort_head -> link;
		}
		else {
			sort_head -> link = pptr;
			sort_head = pptr;
			pptr = sort_head -> link;
		}
	}
	if (ptr == NULL)
		sort_head -> link = pptr;
	if (pptr == NULL)
		sort_head -> link = ptr;
	display(root3);
	return root3;
}
