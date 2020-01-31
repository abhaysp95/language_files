/*.....Program to implement binary Search.....*/

#include<stdio.h>

void Bsearch(int *,int ,int );
void Bsort(int *, int );

int main(){
    int n,a[n],k;
    printf("\nEnter the count and then enter the elements -\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to search -");
    scanf("%d",&k);
    Bsearch(a,k,n);
    return 0;
}

void Bsearch(int *a, int k, int n){
    Bsort(a,n);
    int beg = 0, end = n-1;
    while(beg<=end){
        int mid = (beg+end)/2;
        if(k<a[mid]){
            end = mid;
        }
        else if(k>a[mid]){
            beg=mid;
        }
        else
        {
            printf("\nElement %d found at %d position.\n\n",k,beg);
        }
        beg++;
        
    }
    if(beg>end)
        printf("\nElement not found. Check before entering.\n\n");

}

void Bsort(int *a, int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}