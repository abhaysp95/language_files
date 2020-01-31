/*.....Program to implement merge sort.....*/

#include<stdio.h>
#define size 50

void Sorting(int *,int, int);
void Combine(int *,int ,int ,int );

int main(){
    int n;
    printf("\nEnter the count of numbers for sorting -");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements to sort - ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    Sorting(a,0,n-1);
    printf("\nSorted array is -");
    for(int i = 0;i<n;i++)
        printf("\n%d",a[i]);
    printf("\n\n");
    return 0;
}

void Sorting(int *a,int beg,int end){
    int mid;
    if(beg<end){
        mid = (beg+end)/2;
        Sorting(a,beg,mid);
        Sorting(a,mid+1,end);
        Combine(a,beg,mid,end);
    }
}

void Combine(int *a, int beg, int mid, int end){
    int i = beg, j = mid+1, k = beg,temp[size],l;
    while((i<=mid) && (j<=end)){
        if(a[i]<a[j]){
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=end){
            temp[k]=a[j];
            j++;k++;
        }
    }
    else
    {
        while(i<=mid){
            temp[k]=a[i];
            i++;k++;
        }
    }
    for(l=beg;l<=k;l++){
        a[l]=temp[l];
    }
    
}