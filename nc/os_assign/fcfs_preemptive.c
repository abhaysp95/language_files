/** Name -> Abhay Shanker Pathak
Date -> 2020-02-18
Description -> Program for fcfs preemptive algorithm
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-18 */

#include<stdio.h>
#define size 100

int main(int argc, char *argv[]){
	int pro[size], wt[size], bt[size], at[size], tat[size], i, j, np;
	float val = 0, val1 = 0;
	printf("\nEnter number of process: ");
	scanf("%d", &np);

	// enter burst time
	printf("\nEnter burst time for process: ");
	for (i = 0; i < np; i++) {
		printf("Process %d: ", i+1);
		scanf("%d", &bt[i]);
	}

	// enter arrival time
	printf("\nEnter arrival time for process: ");
	for (i = 0; i < np; i++) {
		printf("Process %d: ", i+1);
		scanf("%d", &at[i]);
	}

	for (i = 0; i < np; i++) {
		pro[i] = i + 1;
	}

	// calculating turn around time
	/* for (i = 0; i < np; i++) { */
	/* 	printf("\nTurn around time for P%d: ", i+1); */
	/* 	val = val + bt[i]; */
	/* 	tat[i] = val; */
	/* 	printf("%d", tat[i]); */
	/* } */

	// calculating waiting time
	// to solve with arrival time either - to complete - arrival to get tat, or just minus
	// arrival to time to wt
	/* val = 0; */
	/* for (i = 0; i< np; i++) { */
	/* 	printf("\nWaiting time of P%d: ", i+1); */
	/* 	val = tat[i] - bt[i] - at[i]; */
	/* 	wt[i] = val; */
	/* 	printf("%d", wt[i]); */
	/* } */

	/* // average waiting and turn around time */
	/* for (i = 0; i < np; i++) { */
	/* 	val = val + tat[i]; */
	/* 	val1 = val1 + wt[i]; */
	/* } */
	/* printf("\nAverage waiting time: %f", val/np); */
	/* printf("\nAverage turn around time: %f", val1/np); */

	/* // sorting arrival time */

	int temp;
	for (i = 0; i < np - 1; i++) {
		for (j = 0; j < np - i -1; j++) {
			if (at[j] > at[j+1]) {
				temp = at[j];
				at[j] = at[j+1];
				at[j+1] = temp;

				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;

				temp = pro[j];
				pro[j] = pro[j+1];
				pro[j+1] = temp;
			}
		}
	}

	// checking sort, to be sure
	/* for (i = 0; i < np; i++) { */
	/* 	printf("\n%d", at[i]); */
	/* } */

	/* for (i = 0; i < np; i++) { */
	/* 	printf("\n%d", bt[i]); */
	/* } */

	// tat
	for (i = 0; i < np; i++) {
		/* printf("\nTurn around time for P%d: ", pro[i]); */
		val = val + bt[i] - at[i] + at[i-1];
		tat[i] = val;
		/* printf("%d", tat[i]); */
	}

	// wt
	for (i = 0; i < np; i++) {
		/* printf("\nwaiting time for P%d: ", pro[i]); */
		val = tat[i] - bt[i];
		wt[i] = val;
		/* printf("%d", wt[i]); */
	}

	for (i = 0; i < np - 1; i++) {
		for (j = 0; j < np - i -1; j++) {
			if (pro[j] > pro[j+1]) {
				temp = pro[j];
				pro[j] = pro[j+1];
				pro[j+1] = temp;

				temp = tat[j];
				tat[j] = tat[j+1];
				tat[j+1] = temp;

				temp = wt[j];
				wt[j] = wt[j+1];
				wt[j+1] = temp;
			}
		}
	}

	for (i = 0; i < np; i++) {
		printf("\n\nTurn around Time for process P%d: ", pro[i]);
		printf("%d", tat[i]);
		// pro[i] isn't necessary here for numbering, it's just to bind values with process
		printf("\nWaiting time for process P%d: ", i+1);
		printf("%d", wt[i]);
	}

	// average waiting and turn around time
	val = 0;
	for (i = 0; i < np; i++) {
		val = val + tat[i];
		val1 = val1 + wt[i];
	}

	printf("\n\nAverage waiting time: %.2f", val1/np);
	printf("\nAverage turn around time: %.2f", val/np);
	return 0;
}
