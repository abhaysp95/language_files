// header file

#ifndef _GUARD_UTIL_HPP_
#define _GUARD_UTIL_HPP_

/**
  Linked list node
  */

struct node {
	int data;
	struct node *next;
};

void push(struct node **head, int data);

void print_list(struct node *head);

void free_list(struct node **head);

#endif