/* Program to read 3*3 matrix */

#include<stdio.h>

/* void display(int *(mat[3]+3)); */
void display(int ((*mat)[3]));
int i, j, mat[3][3];
int main(int arc, char *argv[]){
    printf("\nEnter the elements of matrix- ");
    int k=1;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("\n%d: ",k++);
            scanf("%d",&mat[i][j]);
        }
    }
    display(mat);
    return 0;
}

void display(int ((*mat)[3])){
    printf("\nThe elements of the matrix are- ");
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++)
            printf("\t%d",*(*(mat+i)+j));
    }
}
