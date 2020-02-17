/** Name -> Abhay Shanker Pathak
Date -> 2020-02-16
Description -> Operations on single linked list
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-16 */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
} *root = NULL;

struct node *create_ll(struct node *);

int main(int argc, char *argv[]){
	int ch;
	do {
		printf("### Enter choices: ###");
		printf("\n1: Create a list");
		printf("\n2: Display the list");
		printf("\n3: Add a node at begining");
		printf("\n4: Add a node at end");
		printf("\n5: Add a node before a given node");
		printf("\n6: Add a node after a given node");
		printf("\n7: Delete a node from the begining");
		printf("\n8: Delete a node from the end");
		printf("\n9: Delete a given node");
		printf("\n10: Delete a node after a given node");
		printf("\n11: Delete the entire list");
		printf("\n12: Sort the list");
		printf("\n13: EXIT");
		printf("\nEnter the options: ");
		scanf("%d", &ch);

		switch(ch) {
			// passing the address for first node in root
			case 1: root = create_ll(root);
					printf("\nLinked list created");
					break;
			case 2: root = display(root);
					break;
			case 3: root = insert_beg(root);
					break;
			case 4: root = insert_end(root);
					break;
			case 5: root = insert_before(root);
					break;
			case 6: root = insert_after(root);
					break;
			case 7: root = delete_beg(root);
					break;
			case 8: root = delete_end(root);
					break;
			case 9: root = delete_node(root);
					break;
			case 10: root = delete_after(root);
					 break;
			case 11: root = delete_list(root);
					 break;
			case 12: root = sort_list(root);
					 break;
		}
	}while(ch != 13);
	return 0;
}

struct node *create_ll(struct node *root) {
	struct node *temp, *ptr;
	int num;
	printf("\nEnter -1 to end\nEnter the data: ");
	scanf("%d", &num);
	while (num != -1) {
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> data = num;
		temp -> link = NULL;
		if (root == NULL)
			root = temp;
		else {
			while (ptr -> link != NULL)
				ptr = ptr -> link;
			ptr -> link = temp;
			temp -> link = NULL;
		}
		printf("\nEnter the data: ");
		scanf("%d", &num);
	}
	return root;
}

struct node *display(struct node *root) {
	struct node *ptr;
	ptr = root;
	while (ptr != NULL) {
		printf("\n%d", ptr -> data);
		ptr = ptr -> next;
	}
	return root;
}

struct node *insert_beg(struct node *root) {
	struct node *temp;
	int num;
	printf("\nEnter the data: ");
	scanf("%d", &num);
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = num;
	temp -> link = root;
	root = temp;
	return root;
}

struct node *insert_end(struct node *root) {
	struct node *ptr, *temp;
	int num;
	printf("\nEnter the data: ");
	scanf("%d", &num);
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = num;
	temp -> link = NULL;
	/* list will be created first, so start will not be NULL */
	ptr = root;
	while (ptr -> link != NULL)
		ptr = ptr -> link;
	ptr -> link = temp;
	/* temp -> link = NULL; */
	return root;
}

struct node *insert_before(struct node *root) {
	struct node *temp, *ptr, *preptr;
	int num, val;
	printf("\nEnter the element: ");
	scanf("%d", &num);
	printf("\nEnter the value before which to be inserted: ");
	scanf("%d", &val);
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = num;
	temp -> link = NULL;
	ptr = root;
	while (ptr -> data != val) {
		preptr = ptr;
		ptr = ptr -> link;
	}
	preptr -> link = temp;
	temp -> link = ptr;
	return root;
}

struct node *insert_after(struct node *root) {
	struct node *temp, *ptr, *preptr;
	int num, val;
	printf("\nEnter the element: ");
	scanf("%d", &num);
	printf("\nEnter the value to which to insert after: ");
	scanf("%d", &val);
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = num;
	temp -> link = NULL;
	preptr = root;
	ptr = preptr;
	while (preptr -> data != val) {
		preptr = ptr;
		ptr = ptr -> link;
	}
	preptr -> link = temp;
	temp -> link = ptr;
	return root;
}

