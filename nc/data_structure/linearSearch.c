/*.....Program to implement linear search.....*/

#include<stdio.h>

void Lsearch(int *, int ,int );

int main(){
    int n,a[n],k;
    printf("\nEnter the count of elements -");
    scanf("%d",&n);
    //int a[n];
    printf("\nEnter the elements - ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEnter the element to search -");
    scanf("%d",&k);
    Lsearch(a,k,n);
    return 0;
}

void Lsearch(int *a, int k, int n){
    int l = 0;
    for(int i = 0;i<n;i++){
        if(a[i]==k){
            printf("\nElement %d found at position %d.\n",k,i);
            l++;
        }    
    }
    if(l==0)
        printf("\nElement not found. Please check it\n\n");
}