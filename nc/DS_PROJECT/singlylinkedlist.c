/*...All the operations of singly linked list...*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *display(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

int main()
{
	int ch;
	do
	{
		printf("\nEnter the choice -");
		printf("\n1: create list , 2: display list , 3: add node at begining, 4: add node at end");
		printf("\n5: add node after a given node , 6: add node before a given node , 7: Delete node from beginging");
		printf("\n8: delete node from end , 9: delete a given node, 10: delete a node after a given node");
		printf("\n11. delete the entire list , 12: sort list, 13 :exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: start = create(start);
			printf("\nLinked list created");
			break;

			case 2: start = display(start);
			break;

			case 3: start = insert_beg(start);
			break;

			case 4: start = insert_end(start);
			break;

			case 5: start = insert_after(start);
			break;

			case 6: start = insert_before(start);
			break;

			case 7: start = delete_beg(start);
			break;

			case 8: start = delete_end(start);
			break;

			case 9: start = delete_node(start);
			break;

			case 10: start = delete_after(start);
			break;

			case 11: start = delete_list(start);
			printf("\nLinked list deleted\n");
			break;

			case 12: start = sort_list(start);
			break;

			case 13: printf("\nExiting now! Bye \n");
			break;

			default: printf("Wrong choice. Make right choice \n");
			break;
		}
	}while(ch!=13);
	return 0;
}

struct node *create(struct node *start)
{
	struct node * new, *ptr;
	int num;
	printf("\nEnter '-1' to cancel\n");
	printf("\nEnter the element : ");
	scanf("%d",&num);
	while(num!=-1)
	{
		new = (struct node *)malloc(sizeof(struct node));
		new->data = num;
		if(start==NULL)
		{
			new->next = NULL;
			start = new;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
				ptr->next=new;
				new->next=NULL;
		}
		printf("\nEnter the element : ");
		scanf("%d", &num);
	}
	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *new;
	int num;
	printf("\nEnter the data - ");
	scanf("%d",&num);
	new = (struct node *)malloc(sizeof(struct node ));
	new->data = num;
	new->next = start;
	start = new;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *ptr, *new;
	int num;
	printf("Enter the element : ");
	scanf("%d",&num);
	new = (struct node *)malloc(sizeof(struct node));
	new->data = num;
	new->next = NULL;
	ptr = start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next = new;
	return start;
}

struct node *insert_after(struct node *start)
{
	struct node *new, *ptr, *pptr;
	int num, val;
	printf("\nEnter the element : ");
	scanf("%d",&num);
	printf("\nEnter the element after which new element should be entered : ");
	scanf("%d",&val);
	new = (struct node *)malloc(sizeof(struct node));
	new->data = num;
	ptr = start;
	pptr = ptr;
	while(pptr->data!=val)
	{
		pptr = ptr;
		ptr = ptr->next;
	}
	pptr->next = new;
	new->next = ptr;
	return start;
}

struct node *insert_before(struct node *start)
{
	struct node *new, *ptr, *pptr;
	int num, val;
	printf("\nEnter the element : ");
	scanf("%d",&num);
	printf("\nEnter the element before which new element should be enetered : ");
	scanf("%d",&val);
	new = (struct node *)malloc(sizeof(struct node));
	new->data = num;
	ptr=start;
	while(ptr->data!=val)
	{
		pptr=ptr;
		ptr = ptr->next;
	}
	pptr->next = new;
	new->next = ptr;
	return start;
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start = start->next;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr, *pptr;
	ptr = start;
	while(ptr->next!=NULL)
	{
		pptr=ptr;
		ptr = ptr->next;
	}
	pptr->next = NULL;
	free(ptr);
	return start;
}

struct node *delete_node(struct node *start)
{
	struct node *ptr, *pptr;
	int val;
	printf("\nEnter the node value to delete : ");
	scanf("%d",&val);
	ptr = start;
	if(ptr->data == val)
	{
		start = delete_beg(start);
		return start;
	}
	else
	{
		while(ptr->data!=val)
		{
			pptr = ptr;
			ptr = ptr->next;
		}
		pptr->next = ptr->next;
		free(ptr);
		return start;
	}
}

struct node *delete_after(struct node *start)
{
	struct node *ptr, *pptr;
	int val;
	printf("\nEnter the node value after which the node is to be deleted : ");
	scanf("%d",&val);
	ptr = start;
	pptr = ptr;
	while(pptr->data!=val)
	{
		pptr = ptr;
		ptr = ptr->next;
	}
	pptr->next = ptr->next;
	free(ptr);
	return start;
}

struct node *delete_list(struct node *start)
{
	struct node *ptr;
	if(start!=NULL)
	{
		ptr = start;
		while(ptr!=NULL)
		{
			printf("\nNext element to be deleted is %d.",ptr->data);
			start = delete_beg(ptr);
			ptr = start;
		}
	}
	return start;
}

struct node *sort_list(struct node *start)
{
	struct node *ptr,*qtr;
	int temp;
	ptr = start;
	while(ptr->next!=NULL)
	{
		qtr = ptr->next;
		while(qtr != NULL)
		{
			if(ptr->data > qtr->data)
			{
				temp = ptr->data;
				ptr->data = qtr->data;
				qtr->data = temp;
			}
			qtr = qtr->next;
		}
		ptr = ptr->next;
	}
	return start;
}
