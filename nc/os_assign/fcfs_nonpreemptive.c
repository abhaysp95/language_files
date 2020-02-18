/** Name -> Abhay Shanker Pathak
Date -> 2020-02-18
Description -> Program for fcfs non-preemptive algorithm
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-18 */

#include<stdio.h>
#define size 100

int main(int argc, char *argv[]){
	int wt[size], bt[size], tat[size], i, np, val = 0, val1 = 0;
	printf("\nEnter number of process: ");
	scanf("%d", &np);
	printf("\nEnter burst time for process: ");
	for (i = 0; i < np; i++) {
		printf("\nProcess %d: ", i+1);
		scanf("%d", &bt[i]);
	}

	// calculating turn around time
	for (i = 0; i < np; i++) {
		printf("\nTurn around time for P%d: ", i+1);
		val = val + bt[i];
		tat[i] = val;
		printf("%d", tat[i]);
	}

	// calculating waiting time
	val = 0;
	for (i = 0; i< np; i++) {
		printf("\nWaiting time of P%d: ", i+1);
		val = tat[i] - bt[i];
		wt[i] = val;
		printf("%d", wt[i]);
	}

	// average waiting and turn around time
	for (i = 0; i < np; i++) {
		val = val + tat[i];
		val1 = val1 + wt[i];
	}
	printf("\nAverage waiting time: %d", val/np);
	printf("\nAverage turn around time: %d", val1/np);
	return 0;
}
