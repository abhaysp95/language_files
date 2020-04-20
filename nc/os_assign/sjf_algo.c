/** Name -> Abhay Shanker Pathak
Date -> 2020-04-18
Description -> Shortest job first algo with no arrival time
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-04-20 */


#include<stdio.h>
#include<stdlib.h>

// pre-declaration of functions <<<
struct Process* enter_data(struct Process* ,int );
struct Process* sort_btime(struct Process* );
struct Process* get_other_values(struct Process* );
struct Process* sort_pnum(struct Process* );
void display(struct Process* );
void list_free(struct Process *);
// >>>

// structure declared <<<
struct Process {
	int pnum;	// process number
	int btime;	// burst time
	int wtime;	// waiting time
	int tatime;	// turn-around time
	struct Process *Link;
} *Start = NULL;
// >>>

// main function <<<
int main(int argc, char* argv[]) {
	int count;
	printf("Enter the total number of processes: ");
	scanf("%d", &count);

	// enter the data
	Start = enter_data(Start, count);

	// sort according to burst time(ascending order)
	Start = sort_btime(Start);

	// getting turn-around time and waiting time
	Start = get_other_values(Start);

	// sort according to process number(ascending order)
	Start = sort_pnum(Start);

	// display the content
	display(Start);

	// free list
	list_free(Start);

	printf("\nValue is: %d", Start -> btime);

	return 0;
}
// >>>

// entering the data of processes <<<
struct Process *enter_data(struct Process *Start, int num) {
	struct Process *temp, *ptr;
	for (int i = 1; i <= num; i++) {
		printf("Enter the burst time for %d process: ", i);
		temp = malloc(sizeof(struct Process));
		temp -> pnum = i;
		scanf("%d", &temp -> btime);
		temp -> Link = NULL;
		if (Start == NULL) {
			Start = temp;
		}
		else {
			ptr = Start;
			while (ptr -> Link != NULL) {
				ptr = ptr -> Link;
			}
			ptr -> Link = temp;
			temp -> Link = NULL;
		}
	}
	return Start;
}
// >>>

// display function <<<
void display(struct Process* Start) {
	struct Process *ptr;
	ptr = Start;
	printf("\nDisplaying the items: \n");
	while (ptr != NULL) {
		printf("Burst time for process p%d: %d\n", ptr -> pnum, ptr -> btime);
		ptr = ptr -> Link;
	}
	ptr = Start;
	while (ptr != NULL) {
		printf("Turn around time for process p%d: %d\n", ptr -> pnum, ptr -> tatime);
		ptr = ptr -> Link;
	}
	ptr = Start;
	while (ptr != NULL) {
		printf("Waiting time for process p%d: %d\n", ptr -> pnum, ptr -> wtime);
		ptr = ptr -> Link;
	}
	/* free(ptr); */
}
// >>>

// sorting burst time <<<
struct Process* sort_btime(struct Process* Start) {
	struct Process *ptr, *pptr;
	ptr = Start;
	while (ptr != NULL) {
		/* printf("In ptr"); */
		pptr = ptr -> Link;
		while (pptr != NULL) {
			/* printf("\nIn pptr"); */
			if (ptr -> btime > pptr -> btime) {
				ptr -> btime = ptr -> btime + pptr -> btime;
				pptr -> btime = ptr -> btime - pptr -> btime;
				ptr -> btime = ptr -> btime - pptr -> btime;

				ptr -> pnum = ptr -> pnum + pptr -> pnum;
				pptr -> pnum = ptr -> pnum - pptr -> pnum;
				ptr -> pnum = ptr -> pnum - pptr -> pnum;
			}
			pptr = pptr -> Link;
		}
		ptr = ptr -> Link;
	}
	return Start;
}
// >>>

// getting values of turn around time and burst time <<<
struct Process* get_other_values(struct Process *Start) {
	struct Process* ptr, *pptr;
	ptr = Start;
	pptr = ptr -> Link;
	ptr -> tatime = ptr -> btime;
	pptr -> tatime = ptr -> btime;
	ptr -> wtime = ptr -> tatime - ptr -> btime;
	ptr = ptr -> Link;
	pptr = ptr -> Link;
	while (ptr != NULL) {
		ptr -> tatime += ptr -> btime;
		pptr -> tatime = ptr -> tatime;
		ptr -> wtime = ptr -> tatime - ptr -> btime;
		ptr = ptr -> Link;
		if (pptr -> Link != NULL) {
			pptr = ptr -> Link;
		}
	}
	return Start;
}
// >>>

// sorting according to process number <<<
struct Process* sort_pnum(struct Process* Start) {
	struct Process *ptr, *pptr;
	ptr = Start;
	while (ptr != NULL) {
		/* printf("In ptr"); */
		pptr = ptr -> Link;
		while (pptr != NULL) {
			/* printf("\nIn pptr"); */
			if (ptr -> pnum > pptr -> pnum) {
				ptr -> pnum = ptr -> pnum + pptr -> pnum;
				pptr -> pnum = ptr -> pnum - pptr -> pnum;
				ptr -> pnum = ptr -> pnum - pptr -> pnum;

				ptr -> btime = ptr -> btime + pptr -> btime;
				pptr -> btime = ptr -> btime - pptr -> btime;
				ptr -> btime = ptr -> btime - pptr -> btime;

				ptr -> tatime = ptr -> tatime + pptr -> tatime;
				pptr -> tatime = ptr -> tatime - pptr -> tatime;
				ptr -> tatime = ptr -> tatime - pptr -> tatime;

				ptr -> wtime = ptr -> wtime + pptr -> wtime;
				pptr -> wtime = ptr -> wtime - pptr -> wtime;
				ptr -> wtime = ptr -> wtime - pptr -> wtime;
			}
			pptr = pptr -> Link;
		}
		ptr = ptr -> Link;
	}
	return Start;
}
// >>>

// free the list <<<
void list_free(struct Process *Start) {
	struct Process *ptr;
	while (Start != NULL) {
		ptr = Start;
		Start = Start -> Link;
		free(ptr);
	}
}
/* // >>> */
