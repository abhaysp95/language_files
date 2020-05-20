/** Name -> Abhay Shanker Pathak
Date -> 2020-05-06
Description -> Priority Scheduling algorithm with arrival time
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-05-06 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_proc 15

// struct defination
struct Proc_data {
	int pnum;  // process number
	// priority, lowest num -> highest priority
	int priority;
	float btime;  // burst time
	float atime;  // arrival time
	float wtime;  // waiting time
	float tatime;  // turn around time
};

// function predeclaration
void get_wtime_tatime(struct Proc_data *, float *, int );
void get_avg_wtime_tatime(struct Proc_data *, int );
void display_proc_table(struct Proc_data *, int );

// main function
int main(int argc, char* argv[]) {
	struct Proc_data process[max_proc];
	float temp[max_proc];
	int count;
	printf("Enter the count of the process to evaluate: \n");
	scanf("%d", &count);
	printf("Enter the process arrival time, burst time and priority: \n");
	printf("These data can be space seperated \n");
	printf("Remember, using lowest number as highest priority\n");
	for (int i = 0; i < count; i++) {
		process[i].pnum = i + 1;
		printf("Enter data for process %d: ", i + 1);
		scanf("%f %f %d", &process[i].atime, &process[i].btime, &process[i].priority);
		temp[i] = process[i].btime;
	}

	process[max_proc - 1].btime = 9999;
	process[max_proc - 1].priority = 9999;

	// get waiting time and turnaround time
	get_wtime_tatime(process, temp, count);

	// print table for got waiting time and arrival time
	display_proc_table(process, count);

	// get average time of waiting time and turnaround time
	get_avg_wtime_tatime(process, count);
	return 0;
}

// function to get the values of burst time and turn around time
void get_wtime_tatime(struct Proc_data *process, float *temp, int total) {
	int i = 0, smallest = 0, times = 0, limit = 0;
	double end, sum_wtime = 0, sum_tatime = 0;

	for (times = 0; limit != total; times++) {
		smallest = max_proc - 1;
		for (i = 0; i < total; i++) {
			if (process[i].atime <= times && process[i].priority < process[smallest].priority) {
				if (process[i].btime > 0) {
					smallest = i;
				}
			}
		}
		process[smallest].btime--;
		if (process[smallest].btime == 0) {
			limit++;
			end = times + 1;

			sum_wtime = end - process[smallest].atime - temp[smallest];
			process[smallest].wtime = sum_wtime;

			sum_tatime = end - process[smallest].atime;
			process[smallest].tatime = sum_tatime;
		}
	}
}

// function to get average waiting time and turn around time
void get_avg_wtime_tatime(struct Proc_data *process, int total) {
	double sum_wtime = 0, sum_tatime = 0;
	for (int i = 0; i < total; i++) {
		sum_wtime = sum_wtime + process[i].wtime;
		sum_tatime = sum_tatime + process[i].tatime;
	}
	printf("Average waiting time of these entered processes is: %lf\n", sum_wtime / total);
	printf("Average turnaround time of these entered process is: %lf", sum_tatime / total);
}

// function to get process table with waiting time and arrival time
void display_proc_table(struct Proc_data *process, int total) {
	printf("Waiting time and turn around time for entered processes are: \n");
	printf("Process num\tWaiting time\t\t\tTurn around time\n");
	for (int i = 0; i < total; i++) {
		printf("p%d\t\t%lf\t\t\t%lf\n", process[i].pnum, process[i].wtime, process[i].tatime);
	}
	printf('\n');
}
