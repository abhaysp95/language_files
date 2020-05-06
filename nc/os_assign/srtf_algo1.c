/** Name -> Abhay Shanker Pathak
Date -> 2020-04-21
Description -> SRTF program with array
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-04-21 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_proc 15

// struct defined
struct Proc_data {
	int pnum;     // process number
	float btime;  // burst time
	float atime;  // arrival time
	double wtime; // waiting time
	double tatime;// turn around time
};


// function pre-declaration
void get_avg_values(struct Proc_data *process, int );
void get_other_values(struct Proc_data *process, int *, int );
void display_proc(struct Proc_data *process, int );


// main function
int main(int argc, char* argv[]) {
	struct Proc_data process[max_proc];
	int count;
	int temp[max_proc];
	printf("Enter the total process count: ");
	scanf("%d", &count);
	printf("\nEnter arrival time and burst time for processes: \n");
	for (int i = 0; i < count; i++) {
		process[i].pnum = i + 1;
		printf("Enter arrival time and burst time for process %d: ", process[i].pnum);
		scanf("%f %f", &process[i].atime, &process[i].btime);
		temp[i] = process[i].btime;
	}

	process[max_proc - 1].btime = 9999;

	// get waiting time and turn around time
	get_other_values(process, temp, count);

	// display waiting and turn around time for all processes
	display_proc(process, count);

	// function to get other avg values
	get_avg_values(process, count);

	return 0;
}


// function to get avg waiting and turn around time
void get_avg_values(struct Proc_data *process, int total) {
	// calculating average
	double sum_wtime = 0, sum_tatime = 0;
	for (int i = 0; i < total; i++) {
		sum_wtime = sum_wtime + process[i].wtime;
		sum_tatime = sum_tatime + process[i].tatime;
	}
	printf("Average value of Waiting time for entered processes: %lf", sum_wtime / total);
	printf("\nAverage Turn around time for entered processes: %lf", sum_tatime / total);
}


// function to get values of waiting and turn around time for all process
void get_other_values(struct Proc_data *process, int *temp, int total) {
	int i = 0, times = 0, smallest = 0, limit = 0;
	double end, sum_wtime = 0, sum_tatime = 0;

	for (times = 0; limit != total; times++) {
		smallest = max_proc - 1;
		for (i = 0; i < total; i++) {
			if (process[i].atime <= times && process[i].btime < process[smallest].btime) {
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


// function to display waiting and turn-around time for all processes
void display_proc(struct Proc_data *process, int total) {
	printf("Process name\tWaiting time\t\tTurn around time\n");
	for (int i = 0; i < total; i++) {
		printf("p%d\t\t%lf\t\t\t%lf\n", process[i].pnum, process[i].wtime, process[i].tatime);
	}
}

