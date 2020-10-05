#ifndef UTIL_H
#define UTIL_H

struct node {
	int key;
	struct node *left, *right;
};

// create a node
struct node *newNode(int item);

// Inorder traversal
void inorder(struct node *root);

// Insert a node
struct node *insertNode(struct node *node, int key);

// find inorder successor
struct node *minValueNode(struct node *node);

// delete node
struct node *deleteNode(struct node *root, int key);

#endif
