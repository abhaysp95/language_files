/*** array network ***/

#include<stdio.h>


int main(int argc, char *argv[]){
	int a[5]={5,1,15,20,25};
	int i,j,m;
	i=++a[1];
	j=a[1]++;
	m=a[i++];
	printf("%d, %d, %d",i,j,m);
	return 0;
}



