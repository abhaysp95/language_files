/** Name -> Abhay Shanker Pathak
Date -> 2020-02-28
Description -> insert element at the end of linked list
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-28 */

#include<stdio.h>
#include<stdlib.h>

struct node {
	char data;
	struct node *prev;
	struct node *next;
} *root = NULL;

struct node *insert_end(struct node *);
struct node *display(struct node *);

int main(int argc, char *argv[]){
	// inserting node at end(if list not created then also creating it)
	root = insert_end(root);
	// displaying linked list
	root = display(root);
	return 0;
}

struct node *insert_end(struct node *root)
{
	struct node *temp, *ptr;
	char val;
	printf("\nEnter the element: ");
	scanf("%c", &val);
	while(val != '-') {
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> data = val;
		if (root == NULL) {
			temp -> prev = NULL;
			temp -> next = NULL;
			root = temp;
		}
		else {
			ptr = root;
			while(ptr -> next != NULL)
				ptr = ptr -> next;
			ptr -> next = temp;
			temp -> prev = ptr;
			temp -> next = NULL;
		}
		//printf("Enter the Element: ");
		scanf("%c", &val);
	}
	return root;
}

struct node *display(struct node *root)
{
	printf("\nEntered elements are: ");
	struct node *ptr;
	ptr = root;
	while (ptr -> next != NULL) {
		printf("%c", ptr -> data);
		ptr = ptr -> next;
	}
	return root;
}
