#include<stdio.h>

#include<stdlib.h>
	      void display(struct Node **);
void append(struct Node ** ,int );

    struct Node{
	int data;
	struct Node *next;
    };
int main(){
    struct Node *p;
    printf("Program initializes\n");
    append(&p, 30);
    append(&p, 40);
    append(&p, 50);
    display(&p);
    return 0;
}
void display(struct Node **q)
{             struct Node *temp;
	temp=*q;
	while( temp!=NULL)
	{
	printf(" %d ",temp->data);
       temp=temp->next;
	}
	}
void append(struct Node **q, int num){
    struct Node *temp, *r;
    if(*q==NULL){
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = num;
	temp->next = NULL;
	*q = temp;
    }
    else{
	temp = *q;
	while(temp->next!=NULL)
	    temp = temp->next;
	r = (struct Node *)malloc(sizeof(struct Node));
	r->data = num;
	r->next = NULL;
	temp->next = r;
    }
}
