// main file

/*#include <iostream>*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/util.h"

/**************************************************************************************************/
/* 3. Given only a pointer to a node to be deleted in a singly linked list, how do you delete it? */
/**************************************************************************************************/
void ques3(struct node *target_node) {
	if(target_node->next == NULL) return;
	struct node *temp = target_node->next;
	target_node->data = temp->data;
	target_node->next = temp->next;
	free(temp);
	/** The solution will not work if the node to be deleted is last node */
}


/********************************************************************/
/* 4. Write a C function to print the middle of a given linked list */
/********************************************************************/
/**
 * first method is ofcourse to get count by traversing and then again
 * traversing for count / 2.
 * This is second method */
void ques4_second(struct node *head) {
	if(head == NULL) return;
	struct node *ptr = head, *pptr = ptr;
	while(pptr != NULL && pptr->next != NULL) {
		ptr = ptr->next;
		pptr = pptr->next->next;
	}
	printf("Middle node is: %d\n", ptr->data);
	/** just print ptr now, for both even and odd number of nodes */
	/** but, say there's a condition to print the first node of middle if the number
	 * of nodes is even in the linked list, you will have take third pptr as
	 * reference which will move one node back of ptr and you can print that */
}

void ques4_third(struct node *head) {
	if(head == NULL) return;
	struct node *mid = head;
	size_t count = 0;

	while(head != NULL) {
		if (count & 1) /** if count is odd */
			mid = mid->next;
		count++;
		head = head->next;
	}

	printf("Middle node is: %d\n", mid->data);
}


/*********************************************/
/* 5. Nth node from the end of a Linked List */
/*********************************************/
/**
  * First method will be using length of linked list. There's both iterative
  * and recursive solution. For iterative solution get the length 'len' of the
  * linked list and traverse again for (len - n + 1), where n is Nth node from
  * the end. I'll be showing recursive solution.
  */
void ques5_first(struct node *head, int n) {  /** n is Nth node from end */
	static int count = 0;
	if(head == NULL) return;
	ques5_first(head->next, n);
	if(++count == n) {
		printf("%dth node from end: %d\n", n, head->data);
	}
}

/**
  * Second method will be using double pointers
  */
void ques5_second(struct node *head, int n) {
	if(head == NULL) return;
	struct node *first = head, *second = head;
	for(size_t i = 1; i < n && first != NULL; i++)
		first = first->next;
	if(first == NULL) {
		printf("%d is more than the length of the list\n", n);
		return;
	}
	while(first->next != NULL) {
		second = second->next;
		first = first->next;
	}
	printf("%dth node from end: %d\n", n, second->data);
}


/** Important */
/************************************************/
/* 9. Write a function to reverse a linked list */
/************************************************/
/** itervative method */
void ques9_iterative(struct node **head) {
	struct node *current = *head, *prev = NULL, *next = NULL;
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

/** recursive method */
void ques9_recursive(struct node **head) {
	if(*head == NULL) return;
	struct node *first = *head, *rest = first->next;
	// if list has only one node
	if(rest == NULL) return;
	/** reverse the list and put the first element at the end */
	ques9_recursive(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
}

/** tail recursive approach */
void ques9_recursive_second(struct node *current, struct node *prev, struct node **head) {
	/** if this is last node than mark it as head */
	if(current->next == NULL) {
		*head = current;
		current->next = prev;
		return;
	}
	struct node *next = current->next;
	current->next = prev;
	ques9_recursive_second(next, current, head);
}


/**********************************************************/
/* 10. Write a C function to detect loop in a linked list */
/**********************************************************/
/**
  * VARIATIONS IN SOLUTIONS
  * 1. Use extra attr. for node, which will mark the node as visited
  * 2. A type of extension of above soln, use hash table to store addr. for each node and if addr.
  * 3. Floyd's cycle detection algo (show below)
  */
bool ques10(struct node *head) {
	if(head == NULL) return false;
	struct node *fast = head, *slow = head;
	while(fast != NULL) {
		slow = slow->next;
		fast = (fast->next != NULL) ? fast->next->next : fast->next;
		if(fast == slow) return true;
	}
	return false;
}


/***************************************************************/
/* 11. Function to check if a singly linked list is palindrome */
/***************************************************************/
/* One method is to use stack */
/* other is to reverse the list from middle and compare the two parts */
/* using recursion */

/** solution for second method */
void reverse_list(struct node **head);
bool compare_lists(struct node *first, struct node *second);

bool ques11_mid_reverse(struct node *head) {
	/** first find the mid node.
	  * if linked list is odd in length then middle node will be stored
	  * seperately
	  * get a slow ptr too, to mark as end of first linked list (first part of
	  * divided linked list)
	  */
	struct node *fast_ptr = head, *slow_ptr = head, *prev_slow_ptr = NULL;
	while(fast_ptr != NULL && fast_ptr->next != NULL) {
		prev_slow_ptr = slow_ptr;
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}
	/** check for mid node, if fast_ptr is NULL then linked list is even */
	struct node *mid_node = NULL, *second_half = NULL;
	if(fast_ptr != NULL) {  /** odd length */
		mid_node = slow_ptr;
		slow_ptr = slow_ptr->next;
	}
	/** divide the list */
	prev_slow_ptr->next = NULL;
	second_half = slow_ptr;
	reverse_list(&second_half);  /** reverse second half of linked list */
	bool res = compare_lists(head, second_half);
	/** attach the second half of linked list again */
	reverse_list(&second_half);
	if(fast_ptr != NULL) {  /** odd length */
		prev_slow_ptr->next = mid_node;
		mid_node->next = second_half;
	}
	else {
		prev_slow_ptr->next = second_half;
	}
	return res;
}

void reverse_list(struct node **head) {
	struct node *prev = NULL, *curr = *head, *next = NULL;
	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

bool compare_lists(struct node *first, struct node *second) {
	struct node *fnode = first, *snode = second;
	while(fnode != NULL && snode != NULL) {
		if(fnode->data != snode->data) return false;
		fnode = fnode->next;
		snode = snode->next;
	}
	/** if both are empty return true */
	if(fnode == NULL && snode == NULL) return true;
	return false;  /** if one is NULL and other is not */
}

/** recursive method */
/** the idea here is to treat the recursive function calls as stack */
bool ques11_recursive_util(struct node **left, struct node *right) {
	if(right == NULL) return true;
	bool res = ques11_recursive_util(left, right->next);
	if(res == false) return res;
	res = ((*left)->data == right->data);
	/** move left to next node, not that **left is having the stored address
	 * changed, not **left itself is changing address */
	*left = (*left)->next;
	return res;
}

bool ques11_recursive(struct node *head) {
	/** the function is necessary in the sense, that you are not changing the
	 * head in the main function */
	return ques11_recursive_util(&head, head);
}


int main(int argc, char **argv) {

	struct node *head = NULL;

	/*push(&head, 1);*/
	/*push(&head, 4);*/
	/*push(&head, 3);*/
	/*push(&head, 4);*/
	/*push(&head, 1);*/

	//ques3(head);

	//for(size_t i = 0; i < 5; i++) {
		//push(&head, i);
		//print_list(head);
		//ques4_third(head);
	//}

	//ques5_second(head, 4);
	//ques5_second(head, 2);

	//ques9_iterative(&head);
	//ques9_recursive(&head);
	//ques9_recursive_second(head, NULL, &head);

	/*struct node* lpoint = head->next->next, *ptr = head;*/
	/*while(ptr->next != NULL) ptr = ptr->next;*/
	/*ptr->next = lpoint;*/
	/*printf("loop present: %s\n", ques10(head) ? "YES" : "NO");*/

	/*int numbers[] = {1,2,1,3,1,2,1};*/
	/*size_t size_arr = sizeof(numbers) / sizeof(int);*/
	/*printf("size: %zu\n", size_arr);*/
	/*for(size_t i = 0; i != size_arr; i++) {*/
		/*push(&head, numbers[i]);*/
		/*print_list(head);*/

		/** this approach is changing the head, use bottom one for such loop
		 * like this (or fix it before using) */
		/*printf("Is linked list palindrome: %s\n", ques11_mid_reverse(head) ? "YES" : "NO");*/

		/*printf("Is linked list palindrome: %s\n", ques11_recursive(head) ? "YES" : "NO");*/
	/*}*/


	print_list(head);

	free_list(&head);

	return 0;
}