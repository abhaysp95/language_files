// main file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define max(x, y) ((x > y) ? x : y)

struct tree {
	int value;
	struct tree* left, *right;
};

typedef struct node_detail {
	int value;
	char* child;
} nodedet;

typedef struct node_child_names {
	int value, left_value, right_value;
} ndc_names;

/*#define INIT_NODE_DETAIL(X) ndc_names* X = { X->value = 'q', X->left_value = 'q' X->right_value = 'q'}*/

typedef struct tree stree;

stree* root;

void take_input(int* arr, unsigned int size);
void create_tree(int* arr, unsigned int size);
void preorder(stree* node);
void inorder(stree* node);
void postorder(stree* node);
size_t innernode(stree* node);
size_t node_with_single_children(stree* node);
size_t node_with_single_children_detail(stree* node, nodedet* details);
bool search_node(stree* node, int key);
int height_of_tree(stree* node, int height);
bool get_children_of_node(stree* node, ndc_names* key_node, int key);
/*void free(stree* root);*/

int main(int argc, char **argv) {
	unsigned int size = 0;
	printf("Enter size: ");
	scanf("%u", &size);
	int* arr = (int*)malloc(sizeof(int) * size);
	take_input(arr, size);

	create_tree(arr, size);

	printf("\nPreorder: \n");
	preorder(root);
	printf("\nInorder: \n");
	inorder(root);
	printf("\nPostorder: \n");
	postorder(root);

	printf("\n--------------------");

	size_t innernode_count = innernode(root);
	printf("\ninnernode count: %zu\n", innernode_count);
	printf("leaf nodes: %zu\n", size - innernode_count);

	printf("--------------------\n");

	printf("nodes with single child: %zu\n", node_with_single_children(root));

	printf("--------------------\n");

	nodedet* single_child_nodes_details = (nodedet*)malloc(sizeof(nodedet));
	size_t sc_node_count = node_with_single_children_detail(root, single_child_nodes_details);
	printf("sc_node_count: %zu\n", sc_node_count);
	for (size_t i = 0; i < sc_node_count; ++i) {
		printf("node value: %d ,", (single_child_nodes_details + i)->value);
		printf("child present: %s\n", (single_child_nodes_details + i)->child);
	}

	printf("--------------------\n");

	if (search_node(root, 9)) {
		printf("9 present in tree\n");
	}
	else {
		printf("9 is not present in tree\n");
	}

	printf("--------------------\n");

	int tree_height = height_of_tree(root, 0);
	if (tree_height == -1) {
		printf("No tree exists\n");
	}
	else {
		printf("Height of tree: %d\n", tree_height + 1);
	}

	printf("--------------------\n");

	ndc_names* key_node = (ndc_names*)malloc(sizeof(ndc_names));
	{
		key_node->left_value = 'q';
		key_node->right_value = 'q';
	}
	bool is_node_found = get_children_of_node(root, key_node, 9);
	if (!is_node_found) {
		printf("node with value 2 not found\n");
	}
	else {
		printf("Node found, value: %d, left child: ", key_node->value);
		if (!isalpha(key_node->left_value)) {  // why was isdigit(key_node->left_value) not working
			printf("%d, ", key_node->left_value);
		}
		else {
			printf("None, ");
		}
		printf("right child: ");
		if (!isalpha(key_node->right_value)) {  // isdigit(key_node->right_value) was not working here too
			printf("%d\n", key_node->right_value);
		}
		else {
			printf("None\n");
		}
	}
	return 0;
}

void take_input(int* arr, unsigned int size) {
	for (unsigned int i = 0; i < size; ++i) {
		scanf("%d", (arr + i));
	}
}

void create_tree(int* arr, unsigned int size) {
	/*root = (stree*)malloc(sizeof(stree));   // doing this will make (root != NULL)*/
	for (unsigned int i = 0; i < size; ++i) {
		stree* new_node = (stree*)malloc(sizeof(stree));
		new_node->value = *(arr + i);
		new_node->left = NULL;
		new_node->right = NULL;
		bool duplicate = false;
		if (root == NULL) {
			root = new_node;
		}
		else {  // find the node to which we'll attach new_node
			stree* ptr = root;
			stree* pptr = root;
			while (ptr != NULL) {
				if (new_node->value < ptr->value) {
					pptr = ptr;
					ptr = ptr->left;
				}
				else if (new_node->value > ptr->value) {
					pptr = ptr;
					ptr = ptr->right;
				}
				else {
					duplicate = true;
					break;
				}
			}
			if (duplicate) {
				fprintf(stderr, "Duplicate not allowed\n");
			}
			else {
				if (pptr->value < new_node->value) {
					pptr->right = new_node;
				}
				else if (pptr->value > new_node->value) {
					pptr->left = new_node;
				}
			}
		}
	}
}

void preorder(stree* node) {
	if (node != NULL) {
		printf("%d ", node->value);
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(stree* node) {
	if (node != NULL) {
		inorder(node->left);
		printf("%d ", node->value);
		inorder(node->right);
	}
}

void postorder(stree* node) {
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
		printf("%d ", node->value);
	}
}

size_t innernode(stree* node) {
	static size_t count = 0;
	if (node != NULL) {
		innernode(node->left);
		if (node->left != NULL || node->right != NULL) {
			count++;
		}
		innernode(node->right);
	}
	return count;
}

size_t node_with_single_children(stree* node) {
	static size_t count = 0;
	if (node != NULL) {
		if ((node->left != NULL || node->right != NULL)
				&& (!(node->left != NULL && node->right != NULL))) {
			count++;
		}
		node_with_single_children(node->left);
		node_with_single_children(node->right);
	}
	return count;
}

size_t node_with_single_children_detail(stree* node, nodedet* details) {
	static size_t count = 0;
	if (node != NULL) {
		if ((node->left != NULL || node->right != NULL)
				&& (!(node->left != NULL && node->right != NULL))) {
			count++;
			details = realloc(details, count * sizeof(nodedet));
			(details + count - 1)->value = node->value;
			if (node->left != NULL) {
				(details + count - 1)->child = "left";
			}
			else {
				(details + count - 1)->child = "right";
			}
		}
		node_with_single_children_detail(node->left, details);
		node_with_single_children_detail(node->right, details);
	}
	return count;
}

bool search_node(stree* node, int key) {
	if (node != NULL) {
		if (node->value == key) {
			return true;
		}
		else {
			if (search_node(node->left, key)) {
				return true;
			}
			else if (search_node(node->right, key)) {
				return true;
			}
		}
	}
	return false;
}

int height_of_tree(stree* node, int height) {
	static int max_height = -1;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) {
			max_height = max(max_height, height);
		}
		height_of_tree(node->left, height + 1);
		height_of_tree(node->right, height + 1);
	}
	return max_height;
}

bool get_children_of_node(stree* node, ndc_names* key_node, int key) {
	if (node != NULL) {
		if (node->value == key) {
			key_node->value = node->value;
			if (node->left != NULL) {
				key_node->left_value = node->left->value;
			}
			if (node->right != NULL) {
				key_node->right_value = node->right->value;
			}
			return true;
		}
		else {
			if (get_children_of_node(node->left, key_node, key)) {
				return true;
			}
			else if (get_children_of_node(node->right, key_node, key)) {
				return true;
			}
		}
	}
	return false;
}