/** Name -> Abhay Shanker Pathak
Date -> 2020-03-06
Description -> Find out maximum number of doses to jump through the hurdle
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-06 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int data;
	struct node *link;
} *root = NULL;

struct node *hurdle_heights(struct node *);
struct node *display(struct node *);
struct node *max_and_max(struct node *);
void deleteallnodes(struct node *);
int hurdle_num, max_jump;

int main(int argc, char *argv[]){
	printf("Enter the total number of hurdles: ");
	scanf("%d", &hurdle_num);
	printf("Enter the max of jump height limit of athelete: ");
	scanf("%d", &max_jump);
	// entry of hurdles individual heights in linked list
	root = hurdle_heights(root);
	// display linked list
	root = display(root);
	// max element of linked list and finding if it's max then the max_jump
	root = max_and_max(root);
	// freeing linked list
	deleteallnodes(root);
	return 0;
}

struct node *hurdle_heights(struct node *root) {
	struct node *temp, *ptr;
	int hurdles;
	while(hurdle_num > 0) {
		printf("Enter the hurdle height: ");
		scanf("%d", &hurdles);
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> data = hurdles;
		temp -> link = NULL;
		if (root == NULL)
			root = temp;
		else {
			ptr = root;
			while (ptr -> link != NULL)
				ptr = ptr -> link;
			ptr -> link = temp;
		}
		hurdle_num--;
	}
	return root;
}

struct node *display(struct node *root) {
	struct node *ptr;
	printf("\nDisplaying the hurdles individual heights: ");
	ptr = root;
	while (ptr != NULL) {
		printf("%d\n", ptr -> data);
		ptr = ptr -> link;
	}
	return root;
}

struct node *max_and_max(struct node *root) {
	struct node *ptr;
	ptr = root;
	int max = ptr -> data;
	while (ptr != NULL) {
		if (ptr -> data > max) {
			max = ptr -> data;
		}
		ptr = ptr -> link;
	}
	printf("\nMaximum hurdle height is: %d", max);
	if (max < max_jump)
		printf("\nDoses to take: 0");
	else {
		printf("\nDoses to take is: %d", max - max_jump);
	}
	return root;
}

void deleteallnodes(struct node *root) {
	while (root != NULL) {
		struct node *temp = root;
		root = root -> link;
		free(temp);
	}
}
