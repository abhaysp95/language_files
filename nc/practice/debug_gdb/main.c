/** This program computes sum of the first n prime numbers. Optionally, it
 * allows the user to provide n as command line argument, but defaults to the
 * first n = 10 primes */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** This function takes an integer array (of size n) and returns the sum of its.
 * It returns 0 if the array in NULL or if its size is <= 0 */
long sum(long *arr, int n);

/** This function returns an array containing the first n prime numbers */
long* getPrime(int n);

/** This function determines returns true if the given integer is prime and
 * false otherwise */
int isPrime(int x);

int main(int argc, char **argv) {
	int n = 10;  // default to first 10 primes
	if (argc == 2) {  // first intentional bug
		n = atoi(argv[1]);
	}
	long* primes = getPrime(n);

	long s = sum(primes, n);
	printf("The sum of the first %d primes is %ld\n", n, s);
	free(primes);
	return 0;
}

long sum(long *arr, int n) {
	int i;
	/*int total;  // bug, due to below line(used)*/
	long total = 0;
	for (i = 0; i < n; i++) {
		/*total =+ arr[i];*/
		// bug(this is syntactically correct, it's just like making a
		// value negative)
		total += (long) arr[i];
        }
        return total;
}

long* getPrime(int n) {
	long* result = (long *)malloc(n * sizeof(long));
	/* need variable size array on heap, cause I'm returning this to global
	 * scope and if it's in stack that is not possible, either I have to use
	 * pass by reference for that array or I have to make it static but
	 * since array is VLA(variable length array) that's not possible, so
	 * using malloc */
	result[0] = 2;
	int i = 1;
	int x = 3;
	while (i < n) {
		if (isPrime(x)) {
			result[i] = x;
			i++;
		}
		x += 2;
	}
	return result;
}

int isPrime(int x) {
	if (x < 2) {
		return 0;
	}
	else if (x == 2) {
		return 1;
	}
	else if (x % 2 == 0) {
		return 0;
	}
	for (int i = 3; i <= sqrt(x); i+=2) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}
