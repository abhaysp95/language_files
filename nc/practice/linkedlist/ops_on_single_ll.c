// operations on singly linked list

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

// structure members
struct singlelinkedlist {
	int data;
	struct singlelinkedlist *next;
} *root = NULL;

// prototypes
struct singlelinkedlist *create_node(int );
struct singlelinkedlist *insert_beg(struct singlelinkedlist *);
struct singlelinkedlist *is_root_null(struct singlelinkedlist *);
void insert_before(struct singlelinkedlist *, int );
void insert_after(struct singlelinkedlist *, int );
struct singlelinkedlist *insert_before_or_after(struct singlelinkedlist *, int );
int if_root_null(struct singlelinkedlist *);
struct singlelinkedlist *delete_beg(struct singlelinkedlist *);
struct singlelinkedlist *delete_end(struct singlelinkedlist *);
struct singlelinkedlist *delete_node_of_value(struct singlelinkedlist *);
struct singlelinkedlist *delete_node_before_value(struct singlelinkedlist *);
struct singlelinkedlist *delete_node_after_value(struct singlelinkedlist *);
struct singlelinkedlist *delete_list(struct singlelinkedlist *);
void display(struct singlelinkedlist *);
struct singlelinkedlist *free_node(struct singlelinkedlist *);

// typedef
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

void insert_before(node *new_node, int data) {
	node *ptr, *pptr;
	ptr = root;
	pptr = root;
	while (ptr -> data != data) {
		pptr = ptr;
		ptr = ptr -> next;
	}
	// in case if there's only one node
	if (ptr == pptr) {
		ptr = new_node;
		new_node -> next = pptr;
	}
	else {
		pptr -> next = new_node;
		new_node -> next = ptr;
	}
}

void insert_after(node *new_node, int data) {
	node *ptr, *pptr;
	ptr = root;
	pptr = ptr -> next;
	while (ptr -> data != data && pptr != NULL) {
		ptr = ptr -> next;
		pptr = ptr -> next;
	}
	ptr -> next = new_node;
	new_node -> next = pptr;
}

node *insert_before_or_after(node *root, int condition) {
	int value = 0, data;
	node *new_node;
	if (root == NULL) {
		root = is_root_null(root);
		return root;
	}
	printf("Enter data to match:\n");
	scanf("%d", &data);
	printf("Enter the value to put in linked list:\n");
	scanf("%d", &value);
	new_node = create_node(value);
	if (condition == 0) {
		// it isn't necessary to pass root, it'll not get lost
		insert_before(new_node, data);
	}
	if (condition == 1) {
		insert_after(new_node, data);
	}
	return root;
}

// for delete operations
int if_root_null(node *root) {
	if (root == NULL) {
		printf("There is nothing to delete in linked list\n");
		printf("Insert somethings first\n");
		return 1;
	}
	return 0;
}

node *delete_beg(node *root) {
	node *ptr;
	int flag;
	flag = if_root_null(root);
	if (flag == 1) {
		return root;
	}
	else {
		ptr = root;
		root = root -> next;
		free(ptr);
	}
	return root;
}

node *delete_end(node *root) {
	node *ptr, *pptr;
	int flag;
	flag = if_root_null(root);
	if (flag == 1) {
		return root;
	}
	else {
		ptr = root;
		pptr = root;
		while (ptr -> next != NULL) {
			pptr = ptr;
			ptr = ptr -> next;
		}
		if (ptr == pptr) {
			root = NULL;
		}
		else {
			pptr -> next = NULL;
			free(ptr);
		}
	}
	return root;
}

node *delete_node_of_value(node *root) {
	int value = 0, flag;
	node *ptr, *pptr;
	flag = if_root_null(root);
	if (flag == 1) {
		return root;
	}
	else {
		printf("Enter the value of which node to delete:\n");
		scanf("%d", &value);
		ptr = root;
		pptr = ptr;
		while (ptr -> data != value && ptr -> next != NULL) {
			pptr = ptr;
			ptr = ptr -> next;
		}
		if (ptr == root && ptr -> data == value) {
			root = ptr -> next;
			free(ptr);
		}
		else if (ptr -> next == NULL && ptr -> data == value) {
			pptr -> next = NULL;
			free(ptr);
		}
		else if (ptr -> data != value) {
			printf("Entered data doesn't match with any of the data\n");
		}
		else {
			pptr -> next = ptr -> next;
			free(ptr);
		}
	}
	return root;
}

node *delete_node_before_value(node *root) {
	int value, flag;
	node *ptr, *pptr, *ppptr;
	flag = if_root_null(root);
	if (flag == 1) {
		return root;
	}
	else {
		printf("Enter the value to delete its previous node:\n");
		scanf("%d", &value);
		ptr = root;
		pptr = ptr;
		ppptr = ptr;
		while (ptr -> data != value && ptr -> next != NULL) {
			ppptr = pptr;
			pptr = ptr;
			ptr = ptr -> next;
		}
		if (ptr == root) {
			printf("There's nothing before the node data you entered to delete\n");
		}
		else if (pptr == root && ptr -> data == value) {
			root = pptr -> next;
			free(pptr);
		}
		else if (ptr -> data != value) {
			printf("Enter data didn't matched with any of the nodes data\n");
		}
		else {
			ppptr -> next = ptr;
			free(pptr);
		}
	}
	return root;
}

node *delete_node_after_value(node *root) {
	node *ptr, *pptr;
	int value, flag;
	flag = if_root_null(root);
	if (flag == 1) {
		return root;
	}
	// some problem here in deleting not behaving properly in every condition
	else {
		printf("Enter the value to match: \n");
		scanf("%d", &value);
		ptr = root;
		pptr = ptr;
		while (ptr -> data != value && ptr -> next != NULL) {
			pptr = ptr;
			ptr = ptr -> next;
		}
		if (ptr -> data != value) {
			printf("Entered value didn't matched to any of the data in linkedlist\n");
		}
		else if (ptr == root && ptr -> next == NULL) {
			printf("There's nothing after the entered element to delete\n");
		}
		else if (pptr == root && ptr -> data == value) {
			pptr -> next = NULL;
			free(ptr);
		}
		else if (ptr -> data == value && ptr -> next == NULL) {
			printf("There's nothing after the entered element to delete\n");
		}
		else {
			pptr -> next = ptr -> next;
			free(ptr);
		}
	}
	return root;
}

// delete the list
node *delete_list(node *root) {
	int flag;
	flag = if_root_null(root);
	if (flag == 1) {
		return root;
	}
	else {
		root = free_node(root);
	}
	return root;
}

// function to display linked list
void display(node *root) {
	if (root != NULL) {
		node *ptr;
		ptr = root;
		printf("Current Linked list is: \n");
		while (ptr != NULL) {
			printf("%d\n", ptr -> data);
			ptr = ptr -> next;
		}
	}
	else {
		printf("Linked List is currently empty\n");
	}
}

node *free_node(node *root) {
	if (root != NULL) {
		node *ptr = root;
		while (ptr != NULL) {
			root = delete_beg(ptr);
			ptr = root;
		}
	}
	return root;
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
		printf("4. Delete the begining node\n");
		printf("5. Delete the end of linkedlist\n");
		printf("6. Delete a node for the given value\n");
		printf("7. Delete a node before the given value\n");
		printf("8. Delete a node after the given value\n");
		printf("9. Free the linkedlist\n");
		printf("10. Display linked list\n");
		printf("11. Exit\n");
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
				root = delete_beg(root);
				continue;
			case 5:
				root = delete_end(root);
				continue;
			case 6:
				root = delete_node_of_value(root);
				continue;
			case 7:
				root = delete_node_before_value(root);
				continue;
			case 8:
				root = delete_node_after_value(root);
				continue;
			case 9:
				root = delete_list(root);
				continue;
			case 10:
				display(root);
				continue;
			case 11:
				printf("Exiting Now!\n");
				return 0;
			default:
				printf("Enter the right choice\n");
				continue;
		};
	} while (choice != -1);
	return 0;
}
