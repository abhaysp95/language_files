/** Name -> Abhay Shanker Pathak
Date -> 2020-03-21
Description -> Implementing SJF Algorithm
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-21 */

#include<stdio.h>
#include<stdlib.h>

struct list {
	int pro;
	int bt;
	struct list* link;
} *root = NULL;

// prototype declaration <<<
struct list* entry(struct list* ,int );
struct list* display(struct list* );
// >>>

// main function <<<
int main(int argc, char *argv[]){
	int n, i = 0;
	printf("Enter the number of processes: ");
	scanf("%d", &n);

	// filling up the process <<<
	while (n > 0) {
		root = entry(root, i);
		i++;
		n--;
	}
	// >>>

	// display <<<
	root = display(root);
	//>>>
	return 0;
}
// >>>

// function: entry <<<
struct list* entry(struct list* root, int i) {
	struct list* temp;
	int val;
	temp = (struct list*)malloc(sizeof(struct list));
	temp -> pro = i + 1;
	printf("\nEnter the burst time for %d process: ", temp -> pro);
	scanf("%d", &val);
	temp -> bt = val;
	temp -> link = NULL;
	if (root == NULL)
		root = temp;
	else {
		struct list *ptr = root;
		while (ptr -> link != NULL)
			ptr = ptr -> link;
		ptr -> link = temp;
	}
	return root;
}
// >>>

struct list* display(struct list* root) {
	struct list *ptr;
	printf("\nDisplaying information about process: \n");

	// display loop <<<
	ptr = root;
	while (ptr != NULL) {
		printf("Process Number: %d\t", ptr -> pro);
		printf("Burst time: %d\n", ptr -> bt);
		ptr = ptr -> link;
	}
	// >>>
	return root;
}
