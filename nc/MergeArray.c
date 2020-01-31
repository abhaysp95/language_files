#include<stdio.h>
#include<stdlib.h>

#define Max1 5
#define Max2 6

int *insert(int );
void sort(int *,int );
void display(int *,int );
int *merge(int *,int *);

int main(){
    int *a,*b,*c;

    //Insert the element of array
    printf("Enter the elements of first array - \n");
    a=insert(Max1);

    printf("Enter the element of second array- \n");
    b=insert(Max2);
    
    //Sorting of array
    sort(a,Max1);
    sort(b,Max2);

    printf("First Array -\n");
    display(a,Max1);
    printf("Second Array -\n");
    display(b,Max2);

    c = merge(a,b);
    display(c,Max1+Max2);

    return 0;
}

/*Creating function for creating array of given size dynamically*/
int *insert(int size){
    int *arr,i;
    arr = (int *)malloc(sizeof(int)* size);
    for(i=0;i<size;i++){
        printf("Enter the %d element: ",i+1);
        scanf("%d",&arr[i]);
    }
    return arr;
}

/*creating function for sorting of array in ascending order*/
void sort(int *arr,int size){
    int i,temp,j;
    for(i=0;i<size;i++){
        if(arr[j]>arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j++;
        }
    }
}

/*creating function to display the array*/
void display(int *arr,int size){
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

/*creating function to merge two array*/
int *merge(int *a,int *b){
    int *arr;
    int i,j,k;
    int size = Max1+Max2;
    arr = (int *)malloc(sizeof(int) *size);
    for(i=0,j=0,k=0;i<=size;i++){
        if(a[j]<b[k]){
            arr[i]=a[j];
            j++;
            if(j>=Max1){
                for(i++;k<Max2;i++,j++){
                    arr[i]=b[k];
                }
            }
        }
        else{
            arr[i]=b[k];
            k++;
            if(k>=Max2){
                for(i++;j<Max1;i++,j++){
                    arr[i]=a[j];
                }
            }
        }
    }
    return arr;
}