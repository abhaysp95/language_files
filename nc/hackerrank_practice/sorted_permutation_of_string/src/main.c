// main file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	char* node_str;
	struct node* link;
} *root;

void swap(char* a, char* b);
void permute_string(char* str, int start, int end);
int factorial(int size);
void sorted_store_permutation(char *str);
void display_list(struct node* root);
void free_list(struct node* root);

int factorial(int size) {
	if (size <=1) {
		return 1;
	}
	return size * factorial(size - 1);
}

void swap(char* a, char* b) {
	/*printf("Swap a = %c, b = %c\n", *a, *b);*/
	if (*a != *b) {
		char temp = *a;
		*a = *b;
		*b = temp;
	}
}

void display_list(struct node* root) {
	if (root == NULL) {
		printf("Nothing to show\n");
		return;
	}
	struct node* ptr;
	ptr = root;
	while (ptr != NULL) {
		printf("%s\n", ptr->node_str);
		ptr = ptr->link;
	}
}

void free_list(struct node* root) {
	if (root == NULL) {
		struct node* ptr;
		ptr = root;
		while (ptr != NULL) {
			free(ptr);
			ptr = ptr->link;
		}
		free(root);
	}
}

void sorted_store_permutation(char* str) {
	struct node* temp;
	temp = malloc(sizeof(struct node*));
	temp->node_str = malloc(sizeof(str));
	strcpy(temp->node_str, str);
	temp->link = NULL;
	if (root == NULL) {
		root = temp;
	}
	else {
		struct node* ptr, *pptr;
		/* ptr and pptr are not actual node, just the declaration */
		ptr = root;
		bool isbreak = false;
		while (ptr->link != NULL) {
			if (strcmp(ptr->node_str, str) > 0) {
				isbreak = true;
				break;
			}
			pptr = ptr;
			ptr = ptr->link;
		}
		if (isbreak) {
			pptr->link = temp;
			temp->link = ptr;
		}
		else {
			if (strcmp(ptr->node_str, str) > 0) {
				pptr->link = temp;
				temp->link = ptr;
			}
			else {
				ptr->link = temp;
				temp->link = NULL;
			}
		}
	}
}

void permute_string(char* str, int start, int end) {
	if (start == end) {
		/*printf("%s\n", str);*/
		sorted_store_permutation(str);
	}
	else {
		for (int index = start; index <= end; ++index) {
			/*printf("got index = %d, start = %d\n", index, start);*/
			/*printf("above first swap\n");*/
			swap((str + start), (str + index));
			permute_string(str, start+1, end);
			/*printf("above second swap\n");*/
			swap((str + start), (str + index));  // backtracking
			// backtracking here simply mean that, whatever the first swap is making change reverse that change after printing or storing
			/*printf("end of a iteration\n");*/
		}
	}
}

int main(int argc, char **argv) {
	/*char* new_str = "abc";*/  // the "abc" is in the read-only memory and new_str is just pointer to that read-only memory
	// so if you try to modify this string you'll get segfault
	char new_str[] = "abcd";  // this is in modifiable stack
	permute_string(new_str, 0, strlen(new_str)-1);
	display_list(root);
	free_list(root);
    return 0;
}