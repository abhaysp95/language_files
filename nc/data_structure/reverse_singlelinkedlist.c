/** Name -> Abhay Shanker Pathak
Date -> 2020-02-22
Description -> Reverse singly linked list
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-22 */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
} *root = NULL;

struct node *create_ll(struct node *);
struct node *reverse(struct node *);
struct node *display(struct node *);

int main(int argc, char *argv[]){
	root = create_ll(root);
	root = reverse(root);
	return 0;
}

struct node *create_ll(struct node *root)
{
	struct node *temp, *ptr;
	int val, num;
	printf("\nEnter elements\n(-1) to cancel ");
	scanf("%d", &val);
	while (val > 0) {
		printf("\nEnter the count to enter elements: ");
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
		//scanf("%d", &val);
		val--;
	}
	return root;
}

struct node *reverse(struct node *root)
{
	struct node *ptr, *preptr, *prev = NULL, *link = NULL;
	ptr = root;
	preptr = ptr;
	while (ptr != NULL) {
		link = ptr -> link;		// pointing towards next link
		ptr -> link = prev;		// pointing backwards
		prev = ptr;
		ptr = link;
	}
	preptr = prev;
	display(preptr);
	return preptr;
}

struct node *display(struct node *root)
{
	struct node *ptr;
	ptr = root;
	while (ptr != NULL) {
		printf("%d\n", ptr -> data);
		ptr = ptr -> link;
	}
	return root;
}
