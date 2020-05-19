/**
    _    ____  ____
   / \  / ___||  _ \   Abhay Shanker Pathak
  / _ \ \___ \| |_) |  abhaysp9955@gmail.com
 / ___ \ ___) |  __/   https://github.com/coolabhays
/_/   \_\____/|_|

implementing round robin scheduling algorithm
this algorithm is strictly based on time quantum 2 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_proc 15
#define max_ready_proc 100

// struct defination
struct Proc_data {
	int pnum;  // process number
	float btime;  // burst time
	float atime;  // arrival time
	float wtime; // waiting time
	float tatime; // turnaround time
};

// predeclaration
void get_wait_tatime(struct Proc_data *process, float *temp, int *ready_queue, int );
void get_proc_table(struct Proc_data *process, int );
void get_avg_wait_tatime(struct Proc_data *process, int );

// main function
int main(int argc, char* argv[]) {
	struct Proc_data process[max_proc];
	int ready_queue[max_ready_proc];
	float temp[max_proc];  // copy burst time of processes
	int count = 0;
	printf ("Enter the number of processes: ");
	scanf("%d", &count);
	printf("Enter the process arrival time, burst time: \n");
	printf("These data can be space seperated \n");
	printf("Taking time quantum = 2\n");
	for (int i = 0; i < count; i++) {
		process[i].pnum = i + 1;
		scanf("%f %f", &process[i].atime, &process[i].btime);
		temp[i] = process[i].btime;
	}

	printf("you entered: \n");
	for (int i = 0; i < count; i++) {
		printf("%f\t%f\n", process[i].atime, process[i].btime);
	}

	// calling function to get waiting time and turn around time for all processes
	get_wait_tatime(process, temp, ready_queue, count);

	// display process table
	get_proc_table(process, count);

	// display avg waiting and turnaround time
	get_avg_wait_tatime(process, count);
	return 0;
}

// function to get waiting time and turn around time
void get_wait_tatime(struct Proc_data *process, float *temp, int *ready_queue, int total) {
	int j = 0, times = 0, limit = 0;
	double end = 0, sum_wtime = 0, sum_tatime = 0;
	int ready_count = 0, run_count = 0, temp_index = 0;

	for (times = 0; limit != total; times++) {
		if (times == 0) {
			for (j = 0; j < total; j++) {
				if (process[j].atime == times) {
					ready_queue[ready_count] = j;
					ready_count++;
				}
			}
		}
		if (ready_count != 0) {
			for (j = 0; j < total; j++) {
				if (process[j].atime == times + 1) {
					ready_queue[ready_count] = j;
					ready_count++;
				}
			}
			temp_index = ready_queue[run_count];
			if (process[temp_index].btime > 0) {
				process[temp_index].btime--;
				if (process[temp_index].btime != 0 && times % 2 == 0) {
					run_count--;
				}
				if (process[temp_index].btime != 0) {
					if (times % 2 == 1) {
						ready_queue[ready_count] = temp_index;
						ready_count++;
					}
				}
			}
			if (process[temp_index].btime == 0) {
				limit++;
				end = times + 1;

				sum_wtime = end - process[temp_index].atime - temp[temp_index];
				process[temp_index].wtime = sum_wtime;

				sum_tatime = end - process[temp_index].atime;
				process[temp_index].tatime = sum_tatime;
			}
			run_count++;
		}
	}
}

// function to get process table
void get_proc_table(struct Proc_data *process, int total) {
	printf("\nPrinting process table with waiting time and turn around time\n");
	printf("Process num\tWaiting time\t\t\tTurn around time\n");
	for (int i = 0; i < total; i++) {
		printf("p%d\t\t%lf\t\t\t%lf\n", process[i].pnum, process[i].wtime, process[i].tatime);
	}
}

// function to get average waiting and turn around time
void get_avg_wait_tatime(struct Proc_data *process, int total) {
	double sum_wtime = 0, sum_tatime = 0;
	for (int i = 0; i < total; i++) {
		sum_wtime = sum_wtime + process[i].wtime;
		sum_tatime = sum_tatime + process[i].tatime;
	}
	printf("Average waiting time of these entered processes is: %lf\n", sum_wtime / total);
	printf("Average turnaround time of these entered process is: %lf", sum_tatime / total);
}
