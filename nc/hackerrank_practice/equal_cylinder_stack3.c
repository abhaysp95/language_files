/** Name -> Abhay Shanker Pathak
Date -> 2020-03-16
Description -> A more better approach on the same question of this series
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-16 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// typedefs <<<
typedef struct
{
	int stacknum;
	int stacksize;
	int *stackptr;
} stack;
// >>>

// macro <<<
#define PrintStack(N) \
	for (int i = Stack##N.stacksize - 1; i >= 0; i--) \
	{ \
		if (Stack##N.stackptr[i] !=0 ) \
		{ \
			for (int c = 1; c <= Stack##N.stackptr[i]; c++) \
				printf("%d", c); \
		} \
	} \
	printf("\n")
// >>>

// prototype declaration <<<
void getcylindersizes(stack Stack);
int getcommonheight(stack Stack1,stack Stack2,stack Stack3);
int sumStack(stack Stack);
int getHighestStack(stack Stack1,stack Stack2,stack Stack3);
void removeCylinder(stack Stack);
void printStacks(stack Stack1,stack Stack2,stack Stack3);
// >>>

// main function <<<
int main(int argc, char *argv[]){
	stack Stack1 = {1, 0, (int *)0};
	stack Stack2 = {2, 0, (int *)0};
	stack Stack3 = {3, 0, (int *)0};

	int result = 0;

	// get number of stack elements
	printf("give 3 space seperated values: ");
	scanf("%d %d %d", &(Stack1.stacksize), &(Stack2.stacksize), &(Stack3.stacksize));

	// allocate memory for int arrays
	Stack1.stackptr = (int *)malloc(sizeof(int)*Stack1.stacksize);
	Stack2.stackptr = (int *)malloc(sizeof(int)*Stack2.stacksize);
	Stack3.stackptr = (int *)malloc(sizeof(int)*Stack3.stacksize);

	// fill arrays
	getcylindersizes(Stack1);
	getcylindersizes(Stack2);
	getcylindersizes(Stack3);

	// find highest common height
	result = getcommonheight(Stack1, Stack2, Stack3);

	printf("The highest common height is: %d\n", result);

	return 0;
}
// >>>

// function getcylindersizes <<<
void getcylindersizes(stack Stack)() {
	printf("give %d cylinder size for stack %d\n", Stack.stacksize, Stack.stacknum);

	for (int i = 0; i < Stack.stacksize; i++)
	{
		printf("%d of %d", i + 1, Stack.stacksize);
		scanf("%d", &(Stack.stackptr[i]));
	}
}
// >>>

// function: get common height <<<
int getcommonheight(Stack1, Stack2, Stack3)() {
	while(1)
	{
		printStacks(Stack1, Stack2, Stack3);

		if((sumStack(Stack1) == sumStack(Stack2)) && (sumStack(Stack2) == sumStack(Stack3)))
		{
			break;
		}

		switch(getHighestStack(Stack1, Stack2, Stack3))
		{
			case 1:
				removeCylinder(Stack1);
				break;
			case 2:
				removeCylinder(Stack2);
				break;
			case 3:
				removeCylinder(Stack3);
				break;
		}
	}

	return sumStack(Stack1);
}
// >>>

// function: sumstack <<<
int sumStack(stack Stack)() {
	int sum = 0;

	for (int i = 0; i < Stack.stacksize; ++int i) {
		sum += Stack.stackptr[i];
	}

	return sum;
}
// >>>

// function: get higheststack <<<
int getHighestStack(stack Stack1, stack Stack2, stack Stack3)() {
	int highestStack = 1;
	int height1 = sumStack(Stack1);
	int height2 = sumStack(Stack2);
	int height3 = sumStack(Stack3);

	if (height1 > height2)
		highestStack = 1;
	else
		highestStack = 2;

	if (highestStack == 1) {
		if (height1 > height3)
			highestStack = 1;
		else
			highestStack = 3;
	}
	else {
		if (height2 > height3)
			highestStack = 2;
		else
			highestStack = 3;
	}

	return highestStack;
}
// >>>

// function: removeCylinder <<<
void removeCylinder(stack Stack)() {
	for (int i = 0; i < Stack.stacksize; i++) {
		if (Stack.stackptr[i] != 0) {
			Stack.stackptr[i] = 0;
			break;
		}
	}
}
// >>>

// print stack <<<
void printStacks(stack Stack1, stack Stack2, stack Stack3) {
	printf(" ~~~~~~~~~~~~\n");

	PrintStack(1);
	PrintStack(2);
	PrintStack(3);

	printf(" ~~~~~~~~~~~~\n");
}
// >>>
