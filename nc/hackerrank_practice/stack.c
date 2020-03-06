/** Name -> Abhay Shanker Pathak
Date -> temp
Description -> temp
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> temp */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 50

int st[size], top = -1;
void push(int *, int );
void display(int *);

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int val = 0;
	//limit = 0;
    while (val != -1) {
    scanf("%d", &val);
        /* if(limit == -1) */
        /*     break; */
	if(val != -1)
        push(st, val);
    }
    display(st);
    return 0;
}

void push(int *st, int val) {
    if(top != size - 1) {
        top++;
        st[top] = val;
    }
}

void display(int *st) {
	printf("Top is %d", top);
    int i;
    if (top != -1) {
        for (i = top + 1; i >= 0; i--)
            printf("%d\n", st[i]);
    }
}
