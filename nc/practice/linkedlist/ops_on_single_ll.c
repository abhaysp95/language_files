// operations on singly linked list

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct singlelinkedlist {
	int data;
	struct singlelinkedlist *next;
} *root = NULL;

struct singlelinkedlist *create_node(int );
struct singlelinkedlist *insert_beg(struct singlelinkedlist *);
struct singlelinkedlist *is_root_null(struct singlelinkedlist *);
struct singlelinkedlist *insert_before_or_after(struct singlelinkedlist *, int );
void display(struct singlelinkedlist *);

typedef struct singlelinkedlist node;

// create the node
node *create_node(int val) {
	node *ptr;
	ptr = malloc(sizeof(node));
	ptr -> data = val;
	ptr -> next = NULL;
	return ptr;
}

// insert node at begining of linked list
node *insert_beg(node *root) {
	int value = 0;
	node *new_node, *ptr;
	printf("Enter -1 to cancel\n");
	printf("Enter the number: ");
	scanf("%d", &value);
	while (value != -1) {
		new_node = create_node(value);
		if (root == NULL) {
			root = new_node;
		}
		else {
			ptr = root;
			while (ptr -> next != NULL) {
				ptr = ptr -> next;
			}
			ptr -> next = new_node;
		}
		printf("Enter the number: ");
		scanf("%d", &value);
	}
	return root;
}

node *is_root_null(node *root) {
	int value = 0;
	node *new_node;
	printf("Enter value to put in linked list\n");
	scanf("%d", &value);
	new_node = create_node(value);
	root = new_node;
	return root;
}

// fix this function
node *insert_before_or_after(node *root, int condition) {
	int value = 0, data;
	node *new_node, *ptr, *pptr;
	if (root == NULL) {
		root = is_root_null(root);
		return root;
	}
	printf("Enter value of which to put before:\n");
	scanf("%d", &data);
	printf("Enter the value to put in linked list:\n");
	scanf("%d", &value);
	new_node = create_node(value);
	if (condition == 0) {
		printf("cond: %d\n", condition);
		ptr = root;
		pptr = root;
		printf("before while\n");
		while (ptr -> data != data) {
			printf("ptr->data: %d", ptr -> data);
			pptr = ptr;
			ptr = ptr -> next;
		}
		// in case if there's only one node
		if (ptr == pptr) {
			printf("inside nested if\n");
			ptr = new_node;
			new_node -> next = pptr;
		}
		else {
			pptr -> next = new_node;
			new_node -> next = ptr;
		}
	}
	if (condition == 1) {
		ptr = root;
		pptr = ptr -> next;
		while (ptr -> data != data || pptr != NULL) {
			ptr = ptr -> next;
			pptr = ptr -> next;
		}
		ptr -> next = new_node;
		new_node -> next = pptr;
	}
	return root;
}

// function to display linked list
void display(node *root) {
	node *ptr;
	ptr = root;
	printf("Current Linked list is: \n");
	if (ptr == NULL) {
		printf("Linked List is currently empty\n");
	}
	while (ptr != NULL) {
		printf("%d\n", ptr -> data);
		ptr = ptr -> next;
	}
}

// main function
int main(int argc, char* argv[]) {
	int choice = 0, op_choice = 0;
	printf("#------Operations On Linked List------#\n");
	printf("Enter -1 to exit program\n");
	do {
		printf("1. Create or Insert in begining\n");
		printf("2. Insert a node before the given value\n");
		printf("3. Insert a node after the given value\n");
		printf("4. Display linked list\n");
		printf("5. Exit\n");
		scanf("%d", &op_choice);
		switch (op_choice) {
			case 1:
				root = insert_beg(root);
				continue;
			case 2:
				root = insert_before_or_after(root, 0);
				continue;
			case 3:
				root = insert_before_or_after(root, 1);
				continue;
			case 4:
				display(root);
				continue;
			case 5:
				printf("Exiting Now!\n");
				return 0;
			default:
				printf("Enter the right choice\n");
				continue;
		};
	} while (choice != -1);
	return 0;
}
