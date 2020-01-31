/* program practice for linear search */

#include<stdio.h>
#define size 20

void search(int arr[], int );

int main(int arc, char *argv[]){
    int arr[size]={1,2,3,4,5,8,34,645,23,1,45,7,3,2,23,4,6,34,6,1},n;
    printf("\nEnter the value to find ");
    scanf("%d",&n);
    search(arr,n);
    return 0;
}

void search(int arr[], int n){
    for(int i=0;i<size;i++){
        if(arr[i]==n){
            printf("\nValue %d matched in %d index number. ",n,i);
        }
    }
}
