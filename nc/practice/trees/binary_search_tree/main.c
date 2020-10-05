/* operations on binary search tree */

#include <stdio.h>
#include "util.h"

int main(int argc, char **argv) {
	struct node *root = NULL;
	root = insertNode(root, 8);
	root = insertNode(root, 3);
	root = insertNode(root, 1);
	root = insertNode(root, 6);
	root = insertNode(root, 7);
	root = insertNode(root, 10);
	root = insertNode(root, 14);
	root = insertNode(root, 4);

	printf("Inorder traversal: \n");
	inorder(root);

	printf("\nAfter deleting 8:\n");
	root = deleteNode(root, 8);
	printf("Inorder traversal: \n");
	inorder(root);
	printf("\n");
	return 0;
}
