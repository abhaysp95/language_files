/*.....Program to implement Quick Sort.....*/

#include<stdio.h>

int Partition(int *,int ,int );
void QuickSort(int *,int ,int );

int main(){
    int n;
    printf("\nEnter the count of numbers to sort -");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements to sort - ");
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //function for quicksort provided array,begining position and end position
    QuickSort(a,0,n-1);
    printf("\nSorted array is -");
    for(int i = 0; i<n;i++){
        printf("\n%d",a[i]);
    }
    printf("\n\n");
    return 0;
}

void QuickSort(int *a,int beg,int end){
    int loc;
    if(beg<end){
        loc = Partition(a,beg,end);
        QuickSort(a,beg,loc-1);
        QuickSort(a,loc+1,end);
    }
   // return loc; 
}

int Partition(int *a,int beg,int end){
    int left,right,temp,loc,flag = 0;
    loc = left = beg;
    right = end;
    while(flag!=1){
        while((a[loc]<a[right]) && (loc!=right)){
            right-=1;
        }
        if(loc==right)
            flag=1;
        else if(a[loc]>a[right]){
            temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;
            loc = right;
        }
        if(flag!=1){
            while((a[loc]>a[left]) && (loc!=left))
                left+=1;
                if(loc==left)
                    flag = 1;
                else if(a[loc]<a[left]){
                    temp = a[left];
                    a[left] = a[loc];
                    a[loc] = temp;
                    loc = left;
                }
        }
    }
    return loc;
}