/* Program to fill square matrix with 0 in diagonals, 1 in upper triangle and -1 in lower traingle */

# include<stdio.h>
void read_mat(int b[5][5], int );
void display_mat(int c[5][5], int );

int a[5][5], i, j, rc;
int main(int arc, char *argv[]){
    printf("\nEntering values in array");
    printf("\nEnter the values of row or column ");
    scanf("%d",&rc);
    read_mat(a,rc);
    display_mat(a,rc);
    return 0;
}

void read_mat(int b[5][5], int num){
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(i==j)
                b[i][j]=0;
            else if(i>j)
                b[i][j]=-1;
            else
                b[i][j]=1;
        }
    }
}

void display_mat(int c[5][5], int n){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
		printf("new output");
    }
}
