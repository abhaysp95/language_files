/** Name -> Abhay Shanker Pathak Date -> 2020-03-12
Description -> Permutation of Strings
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-12 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void permute(char *, int ,int );
void swap(char *,char * );

int main(int argc, char *argv[]){
	char *ch;
	int n;
	printf("Enter the count: ");
	scanf("%d", &n);
	ch = (char *)malloc(n * sizeof(char));
	printf("\nEnter the string: ");
	/* scanf("%[^\n]%*c", ch); */
	/* fgets(ch, n, stdin); it already has '\n' in stdin*/
	scanf("%s", ch);
	/* printf("\nEntered string is: "); */
	/* for (int i = 0; i < n; i++) */
	/* 	printf("%c", *(ch + i)); */
	permute(ch, 0, n - 1);
	return 0;
}

void permute(char *ch, int start, int end) {
	if (start == end) {
		for (int i = 0; i <= end; i++)
			printf("%c", *(ch + i));
		printf("\n");
	}
	else {
		for (int i = start; i <= end; i++) {
			swap((ch + start), (ch + i));
			permute(ch, start + 1, end);
			swap((ch + start), (ch + i));
		}
	}
	/* printf("\n"); */
}

void swap(char *x, char *y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}
