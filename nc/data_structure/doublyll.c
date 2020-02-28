/** Name -> Abhay Shanker Pathak
Date -> 2020-02-27
Description -> Operations on Doubly linked list
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-27 */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
} *root = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main(int argc, char *argv[]){
	int choice;
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
		//printf("\n9: Delete a given node");
		printf("\n9: Delete a node before a given node");
		printf("\n10: Delete a node after a given node");
		printf("\n11: Delete the entire list");
		//printf("\n12: Sort the list");
		printf("\n12: EXIT");
		printf("\nEnter the options: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: root = create_ll(root);
					printf("\nDoubly linked list created");
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
			case 9: root = delete_before(root);
					break;
			case 10: root = delete_after(root);
					 break;
			case 11: root = delete_list(root);
					 break;
			case 12: printf("\nEXITING NOW!");
					 break;
			default: printf("\nNot a right option");
					 break;
		}
	} while(choice != 12);
	return 0;
}

struct node *create_ll(struct node *root) {
	struct node *ptr, *temp;
	int num;
	printf("\nEnter -1 to end");
	printf("\nEnter the data: ");
	scanf("%d", &num);
	while (num != -1) {
		temp = (struct node *)malloc(sizeof(struct node));
		if (root == NULL) {
			temp -> prev = NULL;
			temp -> data = num;
			temp -> next = NULL;
			root = temp;
		}
		else {
			ptr = root;
			temp -> data = num;
			while (ptr -> next != NULL)
				ptr = ptr -> next;
			ptr -> next = temp;
			temp -> prev = ptr;
			temp -> next = NULL;
		}
		printf("Enter the data: ");
		scanf("%d" ,&num);
	}
	return root;
}

struct node *display(struct node *root) {
	struct node *ptr;
	ptr = root;
	while (ptr != NULL) {
		printf("%d\t", ptr -> data);
		ptr = ptr -> next;
	}
	return root;
}

struct node *insert_beg(struct node *root) {
	struct node *temp;
	int num;
	printf("\n Enter the data: ");
	scanf("%d" ,&num);
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = num;
	root -> prev = temp;
	temp -> prev = NULL;
	temp -> next = root;
	root = temp;
	return root;
}

struct node *insert_end(struct node *root) {
	struct node *temp, *ptr;
	int num;
	printf("\nEnter the data: ");
	scanf("%d", &num);
	temp = (struct node *)malloc(sizeof(struct node));
	ptr = root;
	while (ptr -> next != NULL) {
		ptr = ptr -> next;
	}
	ptr -> next = temp;
	temp -> next = NULL;
	temp -> prev = ptr;
	return root;
}

struct node *insert_before(struct node *root) {
	struct node *temp, *ptr;
	int num, val;
	printf("\nEnter the data: ");
	scanf("%d", &val);
	printf("\nEnter the value to which before this new value to be inserted: ");
	scanf("%d", &num);
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = val;
	ptr = root;
	while (ptr -> data != num)
		ptr = ptr -> next;
	temp -> next = ptr;
	temp -> prev = ptr -> prev;
	ptr -> prev -> next = temp;
	ptr -> prev = temp;
	return root;
}

struct node *insert_after(struct node *root) {
	struct node *temp, *ptr;
	int num, val;
	printf("\nEnter the data: ");
	scanf("%d", &val);
	printf("\nEnter the value after which element to be inserted: ");
	scanf("%d", &num);
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = val;
	ptr = root;
	while (ptr -> data != num)
		ptr = ptr -> next;
	temp -> prev = ptr;
	temp -> next = ptr -> next;
	ptr -> next -> prev = temp;
	ptr -> next = temp;
	return root;
}

struct node *delete_beg(struct node *root) {
	struct node *ptr;
	ptr = root;
	root = root -> next;
	root -> prev = NULL;
	free(ptr);
	return root;
}

struct node *delete_end(struct node *root) {
	struct node *ptr;
	ptr = root;
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> prev -> next = NULL;
	free(ptr);
	return root;
}

struct node *delete_before(struct node *root) {
	struct node *ptr, *preptr;
	int val;
	printf("\nEnter the value before which the node has to be deleted: ");
	scanf("%d", &val);
	ptr = root;
	while (ptr -> data != val)
		ptr = ptr -> next;
	preptr = ptr -> prev;
	if (preptr == root)
		root = delete_beg(root);
	else {
		ptr -> prev = preptr -> prev;
		preptr -> prev -> next = ptr;
	}
	free(preptr);
	return root;
}

struct node *delete_after(struct node *root) {
	struct node *ptr, *preptr;
	int val;
	printf("\nEnter the value to after which the node has to be deleted: ");
	scanf("%d", &val);
	ptr = root;
	while (ptr -> data != val)
		ptr = ptr -> next;
	preptr = ptr -> next;
	ptr -> next = preptr -> next;
	preptr -> next -> prev = ptr;
	free(preptr);
	return root;
}

struct node *delete_list(struct node *root) {
	while (root != NULL)
		root = delete_beg(root);
	return root;
}
