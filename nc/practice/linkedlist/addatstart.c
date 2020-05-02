/** Name -> Abhay Shanker Pathak
Date -> 2020-02-16
Description -> Add nodes at starting of linked list, enter -1 to cancel
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-16b */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
} *root;

int main(int argc, char *argv[]){
	int num;
	struct node* temp, *ptr;
	root = NULL;
	printf("\nEnter the numbers: ");
	scanf("%d", &num);
	while (num != -1) {
		temp = (struct node* )malloc(sizeof(struct node));
		temp -> data = num;
		temp -> link = NULL;
		if (root == NULL) {
			root = temp;
		}
		else {
			temp -> link = root;
			root = temp;
		}
		scanf("%d", &num);
	}

	ptr = root;
	printf("\nEntered numbers are: ");
	while (ptr != NULL) {
		printf("%d\n",ptr -> data);
		ptr = ptr -> link;
	}

	return 0;
}
