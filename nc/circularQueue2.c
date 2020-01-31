/*...Menu driven program for implementation of circular queue by linked list...*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};
struct circqueue{
    struct node *front;
    struct node *rear;
};

struct cirqueue *q;
struct cirqueue *ENQUEUE(struct cirqueue *, int );
struct cirqueue *DEQUEUE(struct cirqueue *);
struct cirqueue *DISPLAY(struct cirqueue *);

int main(){
    int ch,val;
    do{
        printf("\nEnter the choice - \n'1' for ENQUEUE, '2' for DEQUEUE, '3' for Peek, '4' for DISPLAY, '5' to EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("\nEnter the element to ENQUEUE -\n");
                scanf("%d",&val);
                q = ENQUEUE(q,val);
                break;
            }
            case 2:{
                DEQUEUE(q);
                break;
            }
           /* case 3:{
                val = PEEK(q);
                if(val!=-1);
                printf("\nFirst element in the Queue is %d\n",val);
            }*/
            case 4:{
                q = DISPLAY(q);
                break;
            }
        }
    }while(ch!=5);
    return 0;
}

struct cirqueue *ENQUEUE(struct cirqueue *q, int val){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = val;
    if(q->front ==NULL){
        q->front = ptr;
    }
    else
        q->rear->next = ptr;
    q->rear = ptr;
    q->rear->next = q->front;
    return q;
}

struct cirqueue *DEQUEUE(struct cirqueue *q){
    struct node *ptr;
    if(q->front == NULL){
        printf("\nQueue is Empty.\n");
    }
    if(q->front == q->rear){
        ptr = q->front;
        printf("\nDeleted element is %d.\n",ptr->data);
        free(ptr);
        q->front = NULL;
        q->rear = NULL;
    }
    else{
        ptr = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
    }
    return q;
}

struct cirqueue *DISPLAY(struct cirqueue *q){
    struct node *ptr;
    ptr = q->front;
    if(q->front == NULL){
        printf("\nQueue is Empty\n");
    }
    else{
        while(ptr->next!=q->front){
            printf("\n%d",ptr->data);
            ptr = ptr->next;
        }
    }
    return q;
}