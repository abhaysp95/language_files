#include <stdio.h>
#include <float.h>

int main(int argc, char **argv) {
	puts("\nCharacterstics of type float\n");
	printf("Storage size: %zu bytes\n"
			"Smallest positive value: %E\n"
			"Greatest positinve value: %E\n"
			"Precision: %d decimal digits\n",
			sizeof(float), FLT_MIN, FLT_MAX, FLT_DIG);

	puts("\n\nCharacterstics of type double\n");
	printf("Storage size: %zu bytes\n"
			"Smallest positive value: %E\n"
			"Greatest positinve value: %E\n"
			"Precision: %d decimal digits\n",
			sizeof(float), DBL_MIN, DBL_MAX, DBL_DIG);

	puts("\n\nCharacterstics of type long double\n");
	printf("Storage size: %zu bytes\n"
			"Smallest positive value: %LE\n"
			"Greatest positinve value: %Lf\n"
			"Precision: %d decimal digits\n",
			sizeof(float), LDBL_MIN, LDBL_MAX, LDBL_DIG);
	// %e or %E scientific notation for float/double
	// %g or %G same as %e or %E

	puts("\nAn example of float precision");
	double d_var = 12345.6;
	float f_var = (float) d_var;
	printf("The floating-point number\t"
			"%18.10f\n", d_var);
	printf("has been stored in a variable\n"
			"of type float has the value\t"
			"%18.10f\n", f_var);
	printf("The rounding error is\t"
			"%18.10f\n", d_var - f_var);
	return 0;
}
