/*...Menu driven program to implement the operations of singly linked list...*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
struct stack *PUSH(struct stack *,int );
struct stack *POP(struct stack *);
struct stack *DISPLAY(struct stack *);

int main(){
    int ch,val;
    do{
        printf("\nEnter the choice for operation - \n'1' for PUSH, '2' for POP, '3' for DISPLAY, '4' to EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("\nEnter the element -\n");
                scanf("%d",&val);
                top = PUSH(top,val);
                break;
            }
            case 2:{
                top = POP(top);
                break;
            }
            case 3:{
                top = DISPLAY(top);
                break;
            }
            case 4:{
                printf("\nExiting now!\n");
                break;
            }
            default:{
                printf("\nWrong choice. Enter the correct choice.\n");
            }
        }
    }while(ch!=4);
    return 0;
}

struct stack *PUSH(struct stack *top, int val){
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr->data=val;
    if(top==NULL){
        ptr->next = NULL;
        top = ptr;
    }
    else{
        ptr->next = top;
        top = ptr;
    }
    return top;
}

struct stack *POP(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if(top == NULL)
        printf("\nStack Underflow\n");
    else{
        top = top->next;
        printf("\nElement popped out from Stack is %d\n",ptr->data);
        free(ptr);
    }
    return top;
}

struct stack *DISPLAY(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if(top == NULL){
        printf("\nStack is empty\n");
    }
    else{
        while(ptr!=NULL){
            printf("\n%d",ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}