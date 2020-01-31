#include<stdio.h>
#define size 30

int a[size],ch,i=-1,data,c;

void PUSH();
void POP();
void DISPLAY();

int main(){
    
    do{
         printf("\nEnter the choice of operation on stack - \n'1' for PUSH , '2' for POP , '3' for display and '4' to exit \n");
        scanf("%d",&ch);
        switch (ch){
            case 1:{
                PUSH();
                break;
            }
            case 2:{
                POP();
                break;
            }
            case 3:{
                DISPLAY();
                break;
            }
            case 4:{
                printf("\nExit! Bye\n");
            }
            default:{
                printf("\nWrong choice. Enter valid choice - \n");
            }
        }
    }while(ch!=4);
}

void PUSH(){
    if(i>=size-1)
        printf("\nOVERFLOW\n");
    else
    {
        printf("\nEnter the element to push -\n");
        scanf("%d",&data);
        i++;
        a[i] = data;
    }
}

void POP(){
    if(i<=0){
        printf("\nUNDERFLOW\n");
    }
    else
    {
        printf("\nPopped element is %d \n",a[i]);
        i--;
    }
}

void DISPLAY(){
    printf("\nElements inside stack are -\n");
    for(int j = i;j>=0;j--)
        printf("\n%d\n",a[j]);
}