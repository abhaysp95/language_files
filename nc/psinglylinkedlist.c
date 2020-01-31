/*----Program to practice singly linked list----*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create = NULL;
int main()
{
    int ch;
    do {
       printf("\n***MAIN MENU");
       printf("\n1: Create a list");
       printf("\n2: Display the list");
       printf("\n3: Add the node at beginging");
       printf("\n4: Add the node at end");
       printf("\n5: Add a node before the given node");
       printf("\n6: Add a node after a given node");
       printf("\n7: Delete a node from the begining");
       printf("\n8: Delete a node from the end");
       printf("\n9: Delete a give node");
       printf("\n10: Delete a node after a given node");
       printf("\n11: Delete the entire list");
       printf("\n12: Sort the list");
       printf("\n13: EXIT");
       printf("\n\nEnter your option");
       scanf("%d",&ch);
       switch(ch) {
           case 1: start=create_ll(start);
                   printf("\nLinked list created");
                   break;
       }
    } while (ch!=13);
    return 0;
}

struct node *create_ll(struct node *start){
    struct node *new_node;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the element");
    scanf("%d",&num);
    while(num!=-1){
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node -> data = num;
    }
}


