/*...Program for menu driven implementation of Queue with linked list...*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};
struct queue{
	struct node *front;
	struct node *rear;
};
struct queue *q;

//void create(struct queue *);
struct queue *ENQUEUE(struct queue *, int );
struct queue *DEQUEUE(struct queue *);
struct queue *DISPLAY(struct queue *);
int PEEK(struct queue *);

//q->rear = NULL;
//q->front = NULL;(giving error not known)

int main(){
	int val,ch;
	printf("\nprogram working\n");
	//create(q);
	do{
		printf("\nEnter the choice - \n'1' for ENQUEUE, '2' for DEQUEUE, '3' for Peek, '4' for DISPLAY, '5' to EXIT\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				printf("\nEnter the element to insert in queue - \n");
				scanf("%d",&val);
				q=ENQUEUE(q,val);
				break;
			}
			case 2:{
				q = DEQUEUE(q);
				break;
			}
			case 3:{
				val = PEEK(q);
				if(val!=-1)
					printf("\nThe first element is %d",val);
				break;
			}
			case 4:{
				q = DISPLAY(q);
				break;
			}
			case 5:{
				printf("\nExiting now!");
				break;
			}
			default:{
				printf("\nEnter the valid choice.\n");
			}
		}
	}while(ch!=5);
return 0;
}

/*void create(struct queue *q){
	q->rear = NULL;
	q->front = NULL;
}*///giving error for segmentation fault

struct queue* ENQUEUE(struct queue *q, int val){//void can't be used because we are taking return in struct type
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = val;
	if(q->front = NULL){
		q->front = ptr;
		q->rear = ptr;
		q->front->next = q->rear->next = NULL;
	}
	else
	{
		q->rear->next = ptr;
		q->rear = ptr;
		q->rear->next = NULL;
	}
	return q;
}

struct queue *DEQUEUE(struct queue *q){
	struct node *ptr;
	ptr = q->front;
	if(q->front == NULL)
		printf("\nQueue is Empty\n");
	else
	{
		q->front = q->front->next;
		printf("\nElement deleted is %d\n",ptr->data);
		free(ptr);
	}
	return q;
}

struct queue *DISPLAY(struct queue *q){
	struct node *ptr;
	ptr = q->front;
	if(ptr == NULL)
		printf("\nQueue is Empty completely\n");
	else
	{
		while(ptr!=q->rear){
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
		printf("\n%d\n",ptr->data);
	}
	return q;
}

int PEEK(struct queue *q){
	if(q->front == NULL){
		printf("\nQueue is Empty, no element inside.\n");
		return -1;
	}
	else
	{
		return q->front->data;
	}
	
}