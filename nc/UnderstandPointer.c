#include<stdio.h>

int main(){
    int a = 20;
    int *p;
    int **q;
    p = &a;
    q = &p;
    printf("%d\n",a);
    printf("%d\n",p);
    printf("%d\n",q);
    printf("%d\n",*p);
    printf("%d\n",*q);
    printf("%d\n",**q);

    return 0;
}