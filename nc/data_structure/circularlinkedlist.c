/*...Program to implement the operations of circular linked list...*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);


int main(){
    int ch;
    do{
        printf("\nEnter you choice from following entries : ");
        printf("\n1: Create list, 2: Display list, 3: Add node at begining");
        printf("\n4:Add node at end, 5: Delete node from begining, 6:Delete node from end");
        printf("\n7: Delete node after a given node , 8: Delete the entire list, 9: EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: start = create(start);
            printf("\nCircular linked list created.\n");
            break;

            case 3: start = insert_beg(start);
            break;

            case 2: start = display(start);
            break;

            case 4: start = insert_end(start);
            break;

            case 5: start = delete_beg(start);
            break;

            case 6: start = delete_end(start);
            break;

            case 7: start = delete_after(start);
            break;

            case 8: start = delete_list(start);
            printf("\nCircular linked list deleted\n");
            break;

            case 9: printf("\nExiting now! BYE\n");
            break;

            default: printf("\nWrong choice, read carefully and enter correct choice.\n");

        }
    }while(ch!=9);
    return 0;
}

struct node *create(struct node *start){
    struct node *new, *ptr;
    int num;
    printf("\nEnter '-1' to cancel ");
    printf("\nEnter the element : ");
    scanf("%d",&num);
    while(num!=-1){
        new = (struct node *)malloc(sizeof(struct node));
        new->data = num;
        if(start == NULL){
            new->next = new;
            start = new;
        }
        else
        {
            ptr = start;
            while(ptr->next != start)
                ptr = ptr->next;
            ptr->next = new;
            new->next = start;
        }
        printf("\nEnter the element : ");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
         printf("\n%d",ptr->data);
         ptr = ptr->next;
    }
    printf("\n%d",ptr->data);
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new, *ptr;
    int num;
    printf("\nEnter the data : ");
    scanf("%d",&num);
    new = (struct node *)malloc(sizeof(struct node));
    new->data=num;
    ptr=start;
    while(ptr->next!=start)
        ptr = ptr->next;
    ptr->next = new;
    new->next = start;
    start = new;
    return start;
}

struct node *insert_end(struct node *start){
    struct node *ptr, *new;
    int num;
    printf("\nEnter the data : ");
    scanf("%d",&num);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    ptr = start;
    while(ptr->next!=start)
        ptr=ptr->next;
    ptr->next = new;
    new->next = start;
    return start;
}

struct node *delete_beg(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr -> next != start)

 ptr = ptr -> next;
ptr -> next = start -> next;
free(start);
start = ptr -> next;
return start;
}


struct node *delete_end(struct node *start)
{
struct node *ptr, *preptr;
ptr = start;
while(ptr -> next != start)
{

 preptr = ptr;

 ptr = ptr -> next;
}
preptr -> next = ptr -> next;
free(ptr);
return start;
}


struct node *delete_after(struct node *start)
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the value after which the node has to be deleted : ");
scanf("%d", &val);
ptr = start;
preptr = ptr;
while(preptr -> data != val)
{

 preptr = ptr;

 ptr = ptr -> next;
}
preptr -> next = ptr -> next;
if(ptr == start)

 start = preptr -> next;
free(ptr);
return start;
}


struct node *delete_list(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr -> next != start)

 start = delete_end(start);
free(start);
return start;
}

