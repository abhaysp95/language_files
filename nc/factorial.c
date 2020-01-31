#include<stdio.h>

int Fact(int );

int main(){
    int n;
    printf("\nEnter the value -");
    scanf("%d",&n);
    int p = Fact(n);
    printf("\nFactorial of %d is %d\n",n,p);
    return 0;
}

int Fact(int n){
    int f=0;
    if(n>=1){
        printf("%d",n);
        f= n*Fact(n-1);
        printf("\n");
        printf("%d",n);
    }
    else
    {
        return 1;
    }
    return f;
    
}
