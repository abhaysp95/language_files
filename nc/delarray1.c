/*______ Program to delete an element from array ______*/

#include<stdio.h>

int main(){
  int a[50],n,i,p;

  printf("Enter total no. of elements -\n");
  scanf("%d",&n);

  printf("Enter the elements - \n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  printf("Enter the position of the number- \n");
  scanf("%d",&p);

  if(p>=n+1)
    printf("Wrong position. Deletion not possible.");
  else
    for(i=p-1;i<n;i++)
      a[i]=a[i+1];

  printf("Resultant array is- \n");
    for(i=0;i<n-1;i++)
      printf("%d: %d\t",i+1,a[i]);

  return 0;
}
