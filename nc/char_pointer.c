/*** a program with char pointer ***/

#include<stdio.h>


int main(int argc, char *argv[]){
	char *p;
	p="%d\n";
	p++;
	p++;
	printf(p-2,23);
	return 0;
}



