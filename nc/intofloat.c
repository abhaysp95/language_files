/* Convert a number from integer to float */

#include<stdio.h>

float flot(int );
int inte(float );

int main()
{
		float f,fl;
		int i,in;
		printf("\nEnter an integer number- ");
			scanf("%d",&i);
		printf("\nEnter a float number- ");
			scanf("%f",&f);
		fl = flot(i);
		in = inte(f);
			printf("\nNumber from int to float is - %f",fl);
			printf("\nNumber from float to int is - %d",in);
		return 0;
}

float flot(int i)
{
	float x;
	x = (float)i;
	return x;
}

int inte(float f) {
	int y;
	y = (int)f;
	return y;
}
