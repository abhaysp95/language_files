/** Name -> Abhay Shanker Pathak
Date -> 2020-04-20
Description -> Priority Scheduling Algorithm without arrival time
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-04-20 */


#include <stdio.h>
#include <stdlib.h>

// predeclaration of functions <<<
struct Proc_data* create_list(struct Proc_data* ,int );
struct Proc_data* sort_priority(struct Proc_data* );
struct Proc_data* get_other_values(struct Proc_data* );
struct Proc_data* sort_pnum(struct Proc_data* );
void display_list(struct Proc_data* );
void get_avg(struct Proc_data* ,int );
void list_free(struct Proc_data* );
// >>>

// struct defined <<<
struct Proc_data {
	int pnum;		// process number
	float btime;	// burst time
	float wtime;	// waiting time
	float tatime;	// turn-around time
	int priority;	// priority of process
	struct Proc_data *Next;
} *Start = NULL;
// >>>

// main function <<<
int main(int argc, char* argv[]) {
	int total_proc;
	printf("Enter the total number of process: ");
	scanf("%d", &total_proc);

	// list creation
	Start = create_list(Start, total_proc);
	printf("\nOut of create_list function.");

	// sort according to priority(lowest num highest priority)
	Start = sort_priority(Start);

	// getting values in tatime and wtime
	Start = get_other_values(Start);

	// sort according to process number
	Start = sort_pnum(Start);

	// display list
	display_list(Start);

	// get average wtime and tatime
	get_avg(Start, total_proc);

	// free the list
	list_free(Start);

	return 0;
}
// >>>

// creating list <<<
struct Proc_data* create_list(struct Proc_data* Start, int total_proc) {
	struct Proc_data *temp_node, *ptr_node;
	printf("\nEnter the details of processes: \n");
	for (int i = 1; i <= total_proc; i++) {
		temp_node = malloc(sizeof(struct Proc_data));
		temp_node -> pnum = i;
		temp_node -> Next = NULL;
		printf("Enter burst time and priority for process %d: ", i);
		scanf("%f %d", &temp_node -> btime, &temp_node -> priority);

		if (Start == NULL) {
			Start = temp_node;
		}
		else {
			ptr_node = Start;
			while (ptr_node -> Next != NULL) {
				ptr_node = ptr_node -> Next;
			}
			ptr_node -> Next = temp_node;
			temp_node -> Next = NULL;
		}
	}
	return Start;
}
// >>>

// function to display list <<<
void display_list(struct Proc_data* Start) {
	struct Proc_data *ptr_node = Start;
	printf("\nDisplaying data for process: \n");
	printf("Pnum\tWtime\tTatime\n");
	while (ptr_node != NULL) {
		printf("%d\t%f\t\t%f\n", ptr_node -> pnum, ptr_node -> wtime, ptr_node -> tatime);
		ptr_node = ptr_node -> Next;
	}
}
// >>>

// function to sort according priority <<<
struct Proc_data* sort_priority(struct Proc_data* Start) {
	struct Proc_data *ptr_node, *pptr_node;
	ptr_node = Start;
	while (ptr_node != NULL) {
		pptr_node = ptr_node -> Next;
		while (pptr_node != NULL) {
			if (ptr_node -> priority > pptr_node -> priority) {
				ptr_node -> priority += pptr_node -> priority;
				pptr_node -> priority = ptr_node -> priority - pptr_node -> priority;
				ptr_node -> priority -= pptr_node -> priority;

				ptr_node -> btime += pptr_node -> btime;
				pptr_node -> btime = ptr_node -> btime - pptr_node -> btime;
				ptr_node -> btime -= pptr_node -> btime;

				ptr_node -> pnum += pptr_node -> pnum;
				pptr_node -> pnum = ptr_node -> pnum - pptr_node -> pnum;
				ptr_node -> pnum -= pptr_node -> pnum;
			}
			pptr_node = pptr_node -> Next;
		}
		ptr_node = ptr_node -> Next;
	}
	return Start;
}
// >>>

// function to free list <<<
void list_free(struct Proc_data* Start) {
	struct Proc_data *ptr_node;
	while (ptr_node != NULL) {
		ptr_node = Start;
		Start = Start -> Next;
		free(ptr_node);
	}
}
// >>>

// function to get waiting time and turn around time <<<
struct Proc_data* get_other_values(struct Proc_data* Start) {
	struct Proc_data *ptr_node, *pptr_node;
	ptr_node = Start;
	pptr_node = ptr_node -> Next;
	ptr_node -> tatime = ptr_node -> btime;
	pptr_node -> tatime = ptr_node -> btime;
	ptr_node -> wtime = ptr_node -> tatime - ptr_node -> btime;
	ptr_node = ptr_node -> Next;
	pptr_node = ptr_node -> Next;
	while (ptr_node != NULL) {
		ptr_node -> tatime += ptr_node -> btime;
		pptr_node -> tatime = ptr_node -> tatime;
		ptr_node -> wtime = ptr_node -> tatime - ptr_node -> btime;
		ptr_node = ptr_node -> Next;
		if (pptr_node -> Next != NULL) {
			pptr_node = ptr_node -> Next;
		}
	}
	return Start;
}
// >>>

// function to sort list according to process num <<<
struct Proc_data* sort_pnum(struct Proc_data* Start) {
	struct Proc_data *ptr_node, *pptr_node;
	ptr_node = Start;
	while (ptr_node != NULL) {
		pptr_node = ptr_node -> Next;
		while (pptr_node != NULL) {
			if (ptr_node -> pnum > pptr_node -> pnum) {
				ptr_node -> pnum += pptr_node -> pnum;
				pptr_node -> pnum = ptr_node -> pnum - pptr_node -> pnum;
				ptr_node -> pnum -= pptr_node -> pnum;

				ptr_node -> priority += pptr_node -> priority;
				pptr_node -> priority = ptr_node -> priority - pptr_node -> priority;
				ptr_node -> priority -= pptr_node -> priority;

				ptr_node -> tatime += pptr_node -> tatime;
				pptr_node -> tatime = ptr_node -> tatime - pptr_node -> tatime;
				ptr_node -> tatime -= pptr_node -> tatime;

				ptr_node -> wtime += pptr_node -> wtime;
				pptr_node -> wtime = ptr_node -> wtime - pptr_node -> wtime;
				ptr_node -> wtime -= pptr_node -> wtime;

				ptr_node -> btime += pptr_node -> btime;
				pptr_node -> btime = ptr_node -> btime - pptr_node -> btime;
				ptr_node -> btime -= pptr_node -> btime;
			}
			pptr_node = pptr_node -> Next;
		}
		ptr_node = ptr_node -> Next;
	}
	return Start;
}
// >>>

// get average for tatime and wtime <<<
void get_avg(struct Proc_data* Start, int total_proc) {
	struct Proc_data* ptr_node;
	float avg_wt = 0, avg_tat = 0;
	ptr_node = Start;
	while (ptr_node != NULL) {
		avg_wt += ptr_node -> wtime;
		avg_tat += ptr_node -> tatime;
		ptr_node = ptr_node -> Next;
	}
	printf("Avg. waiting time from given data is: %f", avg_wt / total_proc);
	printf("Avg. turn around time from given data is: %f", avg_tat / total_proc);
}
// >>>
