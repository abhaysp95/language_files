/* This program is to test binary search technique which I remember or not */

# include<stdio.h>
# include<stdlib.h>
#define size 15

int main(int arc, char *argv[]){
    int a[size],n,num,key;
    printf("\nEnter the number of elements to enter in array -");
    scanf("%d",&n);
    printf("\nEnter the elements of array -");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nEnter the element to search -");
    scanf("%d",&key);
    selectionsort(a,n);
    BinarySearch(a,key,n);
    return 0;
}

void selectionsort(int a[], int n){
    int pos, k, temp;
    for(k=0;k<n;k++){
        pos=smallest(a,k,n);
        temp=a[k];
        a[k]=
    }
}

void BinarySearch(int a[], int key, int n){
    int beg,mid,end;
    mid = (beg+end)/2;
    if(key=a[mid]){
        printf("\nElement %d found in %d position in array.",key,mid);
    }
    else if(key<a[mid]){
    }
}

