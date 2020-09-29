#include <stdio.h>
#include <string.h>
#include "util.h"

#define NUMVALS 10

int main(int argc, char **argv) {
	double vals[NUMVALS] = {1.2, 5.7, 78.3, 23.0, 0.004, 4.5, 23, 6.8};

	person me;
	strcpy (me.name, "Gandalf");
	me.age = 2019;

	printf("mean: %lf\n", getmean(vals, NUMVALS));
	print_person_info(&me);
	return 0;
}
