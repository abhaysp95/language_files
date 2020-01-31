#include<stdio.h>
#include<malloc.h>

/*structure containing a data part and linked list*/
struct node{
    int data;
    struct node *next;
};

void append(struct node **, int);
void addatbeg(struct node **, int);
void addafter(struct node *, int, int);
void display(struct node *);
void count(struct node *);
void del(struct node **, int);

int main(){
    struct node *p;
    p = NULL;//empty linked list
    printf("No. of elements in the linked list = %d\n",count(p));
    append(&p,14);
    append(&p,30);
    append(&p,25);
    append(&p,42);
    append(&p,17);

    system("cls");//What is this

    display(p);
}
