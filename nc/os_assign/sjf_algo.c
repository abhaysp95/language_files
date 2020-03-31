/** Name -> Abhay Shanker Pathak
Date -> 2020-03-21
Description -> Implementing SJF Algorithm
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-21 */

#include<stdio.h>
#include<stdlib.h>

struct given {
	int pro;
	int bt;
	int at;
	struct given* link;
} *root = NULL;

struct solved {
	int wt;
	int tat;
} *root1 = NULL;

// prototype declaration <<<
struct given* entry(struct given* ,int );
struct given* display(struct given* );
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

	// solving for tat and wt
	root1 = issolved(root, root1);

	// display <<<
	root = display(root);
	//>>>
	return 0;
}
// >>>

// function: entry <<<
struct given* entry(struct given* root, int i) {
	struct given* temp;
	int val;
	temp = (struct given*)malloc(sizeof(struct given));
	temp -> pro = i + 1;
	printf("\nEnter the burst time for %d process: ", temp -> pro);
	scanf("%d", &val);
	temp -> bt = val;
	printf("\nEnter the arrival time for %d process: ", temp -> pro);
	scanf("%d", &(temp -> at));
	temp -> link = NULL;
	if (root == NULL)
		root = temp;
	else {
		struct given *ptr = root;
		while (ptr -> link != NULL)
			ptr = ptr -> link;
		ptr -> link = temp;
	}
	return root;
}
// >>>

struct given* display(struct given* root) {
	struct given *ptr;
	printf("\nDisplaying information about process: \n");

	// display loop <<<
	ptr = root;
	while (ptr != NULL) {
		printf("Process Number: %d\t", ptr -> pro);
		printf("Arrival time: %d\t", ptr -> at);
		printf("\tBurst time: %d\n", ptr -> bt);
		ptr = ptr -> link;
	}
	// >>>
	return root;
}

// function if solved <<<
/* struct solved* issolved(struct given* root, struct solved* root1) { */

/* } */
// >>>
