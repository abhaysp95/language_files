#include <stdio.h>
#include <stdlib.h>
#include "util.h"

// node creation
struct node *newNode(int item) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> key = item;
	temp -> left = temp -> right = NULL;
	return temp;
}

// Inorder traversal
void inorder(struct node *root) {
	if (root != NULL) {
		// Traverse left
		inorder(root -> left);
		// Traverse root
		printf("%d -> ", root -> key);
		// Traverse right
		inorder(root -> right);
	}
}

// Insert node
struct node *insertNode(struct node *node, int key) {
	// return a new node if root is null(tree is empty)
	if (node == NULL) {
		return newNode(key);
	}

	// traverse to right place and insert the node
	if (key < node -> key) {
		node -> left = insertNode(node -> left, key);
	}
	else {
		node -> right = insertNode(node -> right, key);
	}
	return node;
}

// find the inorder successor
struct node *minValueNode(struct node *root) {
	struct node *current = root;

	// find the leftmost leaf
	while (current && current -> left != NULL) {
		current = current -> left;
	}
	return current;
}

// deleting the node
struct node *deleteNode(struct node *root, int key) {
	// Return if tree is empty
	if (root == NULL) {
		return root;
	}

	// find the node to be deleted
	if (key < root -> key) {
		root -> left = deleteNode(root -> left, key);
	}
	else if (key > root -> key) {
		root -> right = deleteNode(root -> right, key);
	}
	else {
		// if the node is with only one child or no child
		if (root -> left == NULL) {
			struct node *temp = root -> right;
			free(root);
			return temp;
		}
		else if (root -> right == NULL) {
			struct node *temp = root -> left;
			free(root);
			return temp;
		}
		// if the node has two children
		struct node *temp = minValueNode(root -> right);
		// place the inorder successor in position of node to be deleted
		root -> key = temp -> key;
		// delete the inorder successor
		root -> right = deleteNode(root -> right, temp -> key);
	}
	return root;
}
