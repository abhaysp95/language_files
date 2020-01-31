/*...Program for menu driven implementation on Circular Queue...*/

#include<stdio.h>
#define size 20

void ENQUEUE();
int DEQUEUE(void);
int PEEK(void);
void DISPLAY();

int a[size],front=-1,rear=-1;

int main(){
    int ch,data;
    do{
        printf("\nEnter the choice - \n'1' for Enqueue, '2' for Dequeue, '3' for peek, '4' for Display, '5' to quit \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                ENQUEUE();
                break;
            }
            case 2:{
                data = DEQUEUE();//error = can't use int for void
                if(data!=-1)
                printf("\nDeleted element is - %d\n",data);
                break;
            }
            case 3:{
                data = PEEK();
                if(data!=-1)
                printf("\nFirst element of Queue is - %d\n",data);
                break;
            }
            case 4:{
                DISPLAY();
                break;
            }
            case 5:{
                printf("\nExiting now!\n");
                break;
            }
            default:{
                printf("\nEnter the correct choice -\n");
            }
        }
    }while(ch!=5);
}

void ENQUEUE(){
    int data;
    printf("\nEnter the element to insert in Queue -\n");
    scanf("%d",&data);
    if(front == 0 && rear == size-1)
        printf("\nOVERFLOW\n");
    else if(front == -1 && rear == -1){
        front = rear =0;
        a[rear] = data;
    }
    else if(front != 0 && rear == size-1){
        rear = 0;
        a[rear] = data;
    }
    else
    {
        rear++;
        a[rear] = data;
    }
}

int DEQUEUE(void){//can't use void as data type else it will give error, check function calling
    int data;
    if(front == -1 && rear == -1){
        printf("\nUNDERFLOW\n");
    return -1;
    }
    data = a[front];
    if(front == rear){
        front = rear = 0;
    }
    else{
        if(front == size-1)
            front = 0;
        else
            front++;
    }
    return data;
}

int PEEK(void){
    if(front==-1&&rear==-1){
        printf("\nQUEUE is currently empty\n");
        return -1;
    }
    else
        return a[front];
}

void DISPLAY(){
    if(front == -1 && rear == -1){
        printf("\nQUEUE is empty\n");
    }
    else{
        if(front>rear){
            for(int i = front;i<size;i++)
                printf("\n%d",a[i]);
            for(int i = 0;i<=rear;i++)
                printf("\n%d",a[i]);
        }
        else
        {
            for(int i = front; i<=rear; i++)
                printf("\n%d",a[i]);
        }
        printf("\n");
    }
}
