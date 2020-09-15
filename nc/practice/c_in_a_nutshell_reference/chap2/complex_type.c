#include <stdio.h>
#include <complex.h>
/*#define __STDC__NO_COMPLEX__*/

// above macro can be defined to indicate the implementation does not include the header file complex.h

int main(int argc, char **argv) {
	// complex and I are macro for _Complex and i(imaginary)
	double complex z = 1.0 + 2.0 * I;
	z *= I;  // rotate 90 degree counter clockwise
	printf("%f + i%f\n", creal(z), cimag(z));
	printf("%f%+fi\n", creal(z), cimag(z));
	printf("%f + %fi\n", creal(z), cimag(z));
	printf("%f %fi\n", creal(z), cimag(z));

	puts("--------------------");

	printf("%lf + i%lf\n", creal(z), cimag(z));
	printf("%lf%+lfi\n", creal(z), cimag(z));
	printf("%lf + %lfi\n", creal(z), cimag(z));
	printf("%lf %lfi\n", creal(z), cimag(z));

	puts("------------------------------------");
	long double complex ldz = CMPLXL(4, -5);
	// same as CMPLXL(long double), there's CMPLX(double) and CMPLXF(float)
	// works with C11, but not allowed in C99
	printf("%g + %gi\n", creal(ldz), cimag(ldz));
	return 0;
}
