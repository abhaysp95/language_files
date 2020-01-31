#include<stdio.h>
#include<string.h>

void function(char *);

int main(){
  char arr[13];
  printf("Enter string-\n");
  scanf("%[^\n]",arr);
  function(arr);
}


void function(char *input) {


  int i = 1;


  char buffer[8];


  int j = 2;


     strcpy(buffer,input);


     printf("%x %x %s\n",i,j,buffer);


}
