#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//Structure containing a data part and link part
struct node{
    int data;
    struct node *next;
};


void append(struct node **, int );
void addatbeg(struct node **, int );
void addafter(struct node **, int );
void display(struct node **);
int count(struct node **);
void del(struct node **, int );

int main(){
    struct node *p;
    p = NULL; //empty linked list
    
    printf("NO. of elements in linked list = %d",count(p));
    append(&p,20);
    append(&p,30);
    append(&p,25);
    append(&p,42);
    append(&p,17);
    
    system ("cls");
    
    display(p);
    
    addtobeg(&p,999);
    addtobeg(&p,888);
    addtobeg(&p,777);
    
    display(p);
    
    addafter(p,7,0);
    addafter(p,2,1);
    addafter(p,5,99);
    
    display(p);
    printf("No. of elements in the linked list = %d\n",count(p));
    
    del(&p,99);
    del(&p,1);
    del(&p,10);
    
    display(p);
    printf("No. of elements in the linked list = %d\n",count(p));
    return 0;
}

//now adding node at the end of the linked list
void append(struct node **q, int num){
    struct node *temp, *r;
    
    if(*q == NULL)//if the list is empty, create first node
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        temp->link = NULL;
        *q = temp;
    }
    else{
        temp = *q;
        
        //go to the last node
        while(temp->link!=NULL)
            temp=temp->link;
            
        //add node to the end
        r = (struct node *)malloc(sizeof(struct node));
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}

//function to add new node at the begining of the linked list
void addtobeg(struct node **q, int num){
    struct node *temp;
    
    //now adding new node
    temp = (struct node)malloc(sizeof(struct node));
    
    temp->data = num;
    temp->link = *q;
    *q = temp;
}

//function to add new node after the specified number of nodes
void addafter(struct node **q, int loc, int num){
    struct node *temp, *r;
    int i;
    temp = q;
    //skip to desired position
    for(i<0;i<loc;i++){
        temp = temp->link;
        
        //if end of linkedlist is encountered
        if(temp==NULL){
            printf("There are less than %d elements\n",loc);
            return;
        }
    }
    
    //inserting new node
    r = (struct node)malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link;
    temp->link = r;
}

//function to display the content of linked list
void display(struct node *q){
    //traverse the entire linked list
    while(q!=NULL){
        printf("%d",q->data);
        q=q->link;
    }
    printf("\n");
}

//function to give the count of nodes present in linked list
int count(struct node *q){
    int c=0;
    //traversing the entire linked list
    while(q!=NULL){
        q=q->link;
        c++;
    }
    return c;
}

//function to delete the specified node from the linked list
void del(struct node **q, int num){
    struct node *old, *temp;
    temp = *q;
    while(temp!=NULL){
        if(temp->data==num){
        //if node which is to be deleted is first in the linked list
        if(temp==*q)
            *q=temp->link;
        //deleting the intermediate nodes in the linked list
        else
            old->link=temp->link;
        //free the memory occupied by the node
        free(temp);
        return;
    }
    
    //traverse the linked list till the last node
        else{
            old = temp;//old points to the previous node
            temp = temp->link; //go to the next node
        }
    }
    printf("Element %d not found\n",num);
}
