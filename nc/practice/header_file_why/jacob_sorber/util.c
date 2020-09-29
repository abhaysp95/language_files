
#include <stdio.h>
#include "util.h"

double getmean(double *values, int length) {
	double sum = 0.0;
	for (int i = 0; i < length; ++i) {
		sum += values[i];
	}
	return sum / (double) length;
}

void print_person_info(person *p) {
	printf("Person: %s is %d years old\n", p -> name, p -> age);
}
