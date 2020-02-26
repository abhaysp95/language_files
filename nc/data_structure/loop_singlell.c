/** Name -> Abhay Shanker Pathak
Date -> 2020-02-26
Description -> Check whether single_ll contains loop or not
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-26 */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
} *root = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *check_loop(struct node *);

int main(int argc, char *argv[]){
	// creation and display of linked list
	root = create_ll(root);
	// loop check in linked list
	check_loop(root);
	return 0;
}

struct node *create_ll(struct node *root) {
	struct node *temp, *ptr;
	int num, val;
	printf("\nEnter the count: ");
	scanf("%d", &num);
	while(num > 0) {
		printf("\nEnter the element: ");
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
	printf("\nElements in linked list are: ");
	while (ptr != NULL) {
		printf("%d\n", ptr -> data);
		ptr = ptr -> link;
	}
	return root;
}

struct node *check_loop(struct node *root) {
	struct node *ptr, *preptr;
	ptr = root;
	preptr = ptr;
	int c = 0;
	while (ptr -> data != preptr -> data) {
		c++;
		ptr = ptr -> link;
		preptr = preptr -> link -> link;
	}
	if (c != 0)
		printf("\nThere is a loop in linked list");
	else
		printf("\nThere isn't a loop in linked list");
	return 0;
}
