/*...Program to implement menu driven Queue operation...*/

#include<stdio.h>
#define size 15

void INSERT();
int DELETE(void);
int PEEK(void);
void DISPLAY();

int a[size], f = -1, r = -1;

int main(){
    int ch,val;
    do{
        printf("\nEnter the operation choice - \n'1' for Enqueue, '2' for Dequeue, '3' for Peek, '4' for Display and '5' to quit \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                INSERT();
                break;
            }
            case 2:{
                val = DELETE();
                if(val!=-1)
                printf("\nElement deleted - %d\n",val);
                break;
            }
            case 3:{
                val = PEEK();
                if(val!=-1)
                printf("\nFirst element in queue is - %d\n",val);
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
                printf("\nWrong choice, please enter correct choice.\n");
            }
        }
    }while(ch!=5);
    return 0;
}

void INSERT(){
    int num;
    printf("\nEnter the element to INSERT -\n");
    scanf("%d",&num);
    if(r>=size-1)
        printf("\nOVERFLOW!\n");
    else if(f == -1 && r == -1)
        f=r=0;
    else
        r++;
    a[r]=num;
}

int DELETE(void){
    int val;
    if(f==-1 || f>r){
        printf("\nUNDERFLOW\n");
        return -1;
    }
    else{
        val = a[f];
        f++;
        if(f>r)
        f = r = -1;
        return val;
    }
}

int PEEK(void){
    int val;
    if(f==-1 || f>r){
        printf("\nQueue is empty\n");
        return -1;
    }
    else{
        return a[f];
    }
}

void DISPLAY(){
    if(f == -1 || f>r)
        printf("\nQueue is Empty\n");
    else
    {
        for(int i = f;i<=r;i++)
            printf("\n%d",a[i]);
    }
    printf("\n");
}