/* Program illustrates two dimensional array and pointer's relation */

# include<stdio.h>

int main(int arc, char *argv[]){
    int a[3][3]={{1,2},{3,4},{5,6}};
    int (*ptr)[3], i, j;
    ptr=a;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d",(*(ptr+i)[j]));
        }
        printf("\n");
    }
    return 0;
}
