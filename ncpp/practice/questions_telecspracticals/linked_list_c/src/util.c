// cpp file for "util.hpp"

#include "../inc/util.h"
#include <stdlib.h>
#include <stdio.h>

void push(struct node **head, int data) {
	struct node *temp = (struct node*)malloc(sizeof(struct node *));
	temp->data = data;
	temp->next = NULL;

	temp->next = *head;
	*head = temp;
}

void print_list(struct node *head) {
	if(head == NULL) { return; }

	printf("%d", head->data);
	struct node *ptr = head->next;
	while(ptr != NULL) {
		printf("->%d", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void free_list(struct node **head) {
	if(*head == NULL) {
		if(head == NULL) {
			return;
		}
		else {
			*head = NULL;
		}
	}
	else {
		struct node *ptr = *head, *pptr = NULL;
		while(ptr != NULL) {
			pptr = ptr->next;
			free(ptr);
			ptr = NULL;
			ptr = pptr;
		}
		*head = NULL;
	}
}

/** from notes */
/*void free_list(struct node **head) {*/
	/*struct node *current = *head, *next = NULL;*/
	/*while(current != NULL) {*/
		/*next = current->next;*/
		/*free(current);*/
		/*current = next;*/
	/*}*/
	/**head = NULL;*/
/*}*/