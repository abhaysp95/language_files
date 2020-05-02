#include<stdio.h>

int Binary (int );
int main()
{
    int n;
    printf("Enter the number to convert- ");
    scanf("%d",&n);
    Binary(n);
    return 0;
}

int Binary (int x)
{
    int a[50],i=0;
    while(x>=0){
        a[i]=x%2;
        x=x/2;
        i++;
    }
    printf("Binary of the number is- ");
    for( ;i>=0;i--){
        printf("%d",a[i]);
    }
    return 0;
}
