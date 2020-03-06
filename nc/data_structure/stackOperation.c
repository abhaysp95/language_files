/** Name -> Abhay Shanker Pathak
Date -> 2020-03-02
Description -> Stack Operations with array
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-02 */

#include<stdio.h>
#include<stdlib.h>
#define size 50

int arrst[size], top = -1;
void push(int *, int );
int pop(int *);
int peek(int *);
void display(int *);


int main(int argc, char *argv[]){
	int val, choice;
	do {
		printf("## Menu ##");
		printf("\n 1. Push ");
		printf("\n 2. Pop");
		printf("\n 3. Peek");
		printf("\n 4. Display");
		printf("\n 5. Exit");
		printf("\n Enter your option: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\n Enter the number to push in stack: ");
				scanf("%d", &val);
				push(arrst, val);
				break;
			case 2:
				val = pop(arrst);
				if(val != -1)
					printf("\n Value popped from stack is %d ", val);
				break;
			case 3:
				val = peek(arrst);
				if (val != -1)
					printf("\n Top value of stack is %d", val);
				break;
			case 4:
				display(arrst);
				break;
		}
	} while (choice != 5);
	return 0;
}

void push(int *arrst, int val) {
	if(top == size - 1)
		printf("\nStack Overflow");
	else {
		top++;
		arrst[top] = val;
	}
}

int pop(int *arrst) {
	int val;
	if (top == -1) {
		printf("\nStack Underflow");
		return -1;
	}
	else {
		val = arrst[top];
		top--;
		return val;
	}
}

int peek(int *arrst) {
	if(top == -1)
	{
		printf("\nStack is empty");
		return -1;
	}
	else
		return(arrst[top]);

}

void display(int *arrst) {
	int i;
	if (top == -1) {
		printf("\n Stack is empty");
	}
	else {
		for (i = top; i >= 0; i--) {
			printf("\n%d", arrst[i]);
		}
	}
}
