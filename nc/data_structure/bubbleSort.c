/*.....Program to implement Bubble Sort.....*/

void Bsort(int *a, int n);

int main(){
    int n;
    printf("\nEnter the count for number to sort -");
    scanf("%d",&n);
    int a[n];

    //Taking entry to store numbers in array
    printf("\nEnter the numbers to sort -");
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    //Created function for bubble sorting
    Bsort (a,n);
    return 0;
}

void Bsort(int* a, int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j = 0;j<n-i;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("\nNumbers after bubble sorting are -");
    for(int i = 0;i<n;i++)
        printf("\n%d",a[i]);
}