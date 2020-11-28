#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv) {
	int a = 0, b = 0;
#pragma omp parallel
	printf("Hello World\n");
#pragma omp parallel for private(a) shared(b)
	for (int i = 0; i < 24; ++i) {
		printf("Iteration %d is processed by thread %d\n", i, omp_get_thread_num());
		printf("a is: %d, b is: %d\n\n", a++, b++);
	}
	/* threads will be created and different loop iterations will be
	 * assigned to different threads and at the end of parallel loops
	 * threads will synchronized and the program execution will proceed
	 * further with serial manner
	 * each thread will have a private copy of variable a
	 * all threads access the same memory location of variable b
	 */

	/* Another way to give private */
#pragma omp parallel
	{
		// code placed here will be exectued by all the threads
		// alternative way of specifying private variables, declare them inside the
		// scope of 'pragma omp parallel'
		int private_num = 0;
#pragma omp for schedule(dynamic, 4)
		for (int i = 0; i < 25; ++i) {
			printf("Iteration %d is processed by thread %d\n", i, omp_get_thread_num());
			printf("private_num is: %d\n\n", private_num++);
		}
		/* dynamic scheduling of the loop of with size of 4,
		   scheduling mode supported by openmp are:
		   * static
		   * dynamic
		   * guided
		*/
	}
	return 0;
}
