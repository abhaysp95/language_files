/*Program to delete given number from array*/

#include<stdio.h>

int main(){
  int arr[10];
  int n,i,x,f,pos;

  printf("Enter the total number of elements- \n");
  scanf("%d",&n);
  printf("Enter the elements- \n");
    for(i=0;i<n;i++){
      printf("%d: ",i+1);scanf("%d",&arr[i]);
    }

  printf("Enter the element to be deleted- \n");
  scanf("%d",&x);

  for(i=0;i<n;i++){
    if(arr[i]==x){
      f=1;pos=i;break;
    }
  }
  if(f==1){
    for( ;i<n-1;i++)
      arr[i]=arr[i+1];

  printf("Resultant array is - \n");
  for(i=0;i<n-1;i++){
    printf("%d: %d\n",i+1, arr[i]);
  }}
  else
    printf("Element not found.");
  return 0;
}
