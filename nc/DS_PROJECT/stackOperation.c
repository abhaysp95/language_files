/*...Menu driven program to perform stack operations...*/

#include<stdio.h>
#define num 9
//#define size 9

void PUSH(int *,int );
//void POP(int *);

int main(){
    int n,a[num],sp=0,data,c;

    printf("\nEnter the choice to PUSH or POP - \nPUSH - 1 \nPOP - 2\n\n");
    scanf("%d",&n);
    switch (n){
        case 1:{
            printf("\nFound 1\n");
            PUSH(a, sp);
            break;
        }
        case 2:{
            printf("\nFound 2\n");
            //POP(a);
            break;
        }
    }
    //printf("\nStack after operation - \n");
    /*for(int i=num;i>=0;i++)
        printf("%d\n",a[i]);
        printf("\n");*/
    return 0;
}

void PUSH(int *a, int sp){
    int data,ch,c=sp,b[9];
    printf("\nEnter the element to PUSH into stack -\n");
    scanf("%d",&data);
    if(sp==num-1)
        printf("\nOverflow. Perform POP\n\n");
    else
    {
        a[sp]=data;

    }
    printf("\nWant to PUSH again - \nEnter '1' else Enter '2' \n");
    scanf("%d",&ch);
    if(ch==1){


        printf("%d",c);
        PUSH(a,sp+1);
    }
    if(ch==2){
        for(int i=0,j=sp+1;i<sp+1 && j>=0;i++,j--){
            b[j]=a[i];

            printf("\n%d",b[i]);
        }
        printf("\n");
    }

}

//void POP(int *a){}

