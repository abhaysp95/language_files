#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>

#define n 2048
double a[n][n];
double b[n][n];
double c[n][n];

float tdiff(struct timeval* start, struct timeval* end) {
	/* struct timeval {
	       long tv_sec;
		   long tv_usec;
		}
	   tv_sec is for second and tv_usec is micro-seconds, so getting difference
	   in seconds and then of micro-seconds and then changing the micro-seconds
	   in second */
	return ((end->tv_sec - start->tv_sec)
			+ 1e-6 *(end->tv_usec - start->tv_usec));
}

int main(int argc, const char **argv) {
	srand(time(0));  // use current time to set seed for rand()
	// if not set, then rand() will use as if srand(1)
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = (double)rand() / (double)RAND_MAX;
			b[i][j] = (double)rand() / (double)RAND_MAX;
			c[i][j] = 0;
		}
	}

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = i + j + 1;
			b[i][j] = i + j + 1;
			c[i][j] = 0;
		}
	}*/

	struct timeval start, end;
	gettimeofday(&start, NULL);

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}*/

	/* In the previous nested loops, b is running in column major order,
	 * means when k is changing everytime it's jumping off to the size of
	 * 2048 blocks(int), for c once it figured out what i and j is it stays
	 * same and loops for k, so c is getting excellent spatial locality and
	 * now a is having linear accessiblity of elements so good spatial
	 * locality and b is having it in column major order, so poor spatial
	 * locality, which is not in the case for below nested loops, there once
	 * it figured out what i and k is it loops for j and thus c is having
	 * linear accessibility so good spatial locality as for 'a' it's still
	 * for full one loop so excellent spatial locality and for b it's again
	 * a linear accessibility so good spatial locality, so in this way
	 * having cache miss-rate is very low in the below loops as compared to
	 * above, and in the same way there are 4 different ways more to place
	 * the loops but the below one is best */

#pragma omp parallel for
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
#pragma omp parallel for
			for (int j = 0; j < n; ++j) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	gettimeofday(&end, NULL);
	printf("%0.6f\n", tdiff(&start, &end));
	return 0;
}

/* you can use following ways to check the speedup

   normally, I would compile like this:
   $ clang -Wall -std=c99 -g source.c executable

   now, you can check the speed up through compiling like this by swapping j and
   k for loop positions

   also you can use compiler optimization flags to more optimize your code, there
   are several flags for this like -O0, -O1, -O2, -O3, -Og, -Os, -Oz etc.
   '-O2' worked best here

   you can use 'valgrind' to check the cache miss-rate for both of the type of loops
   (j and k different pos. for loops) like this:
   $ valgrind --tool=cachegrind executable
   */


/* Cache misses are slow and hits are fast, so try to reuse most of the data already available in cache */
