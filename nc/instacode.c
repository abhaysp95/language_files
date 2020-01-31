/**Testing a code got from instagram*/

#include<stdio.h>
#include<stdlib.h>

enum{false,true};
int main(int argc, char *argv[]){
  int i = 1;
  do{
    printf("%d\n",i);
    i++;
    if(i<15)
    continue;
  }while(false);
  getchar();

  return 0;
}
