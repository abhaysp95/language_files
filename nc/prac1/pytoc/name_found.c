/** Name -> Abhay Shanker Pathak
Date -> 2020-03-25
Description -> Find whether the input name exists or not
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-25 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// main function <<<
int main(int argc, char *argv[]){
	int count, length = 0;
	int *pos;
	char **name;
	printf("\nEnter the count of names: ");
	scanf("%d", &count);

	/* char *name = (char *)malloc((count * 100) * (sizeof(char))); */
	name = malloc(count * sizeof(char *));
	pos = malloc((count + 1) * sizeof(char));

	printf("\nEnter the names: ");
	/* for (int i = 0; i < count; i++) { */
	/* 	scanf("%[^\n]%*c", (name + length)); */
	/* 	length = strlen(name) + 1; */
	/* 	*(pos + i) = length; */
	/* } */
	for (int i = 0; i < count; i++) {
		name[i] = malloc(100 * sizeof(char));
		/* scanf("%[^\n]%*c", (name[i])); */
		fgets(name[i], sizeof(name[i]), stdin);
		printf("\nlength of string is: %zu", strlen(name[i]));
	}

	//testing
	/* printf("Names are: %s\n", name); */
	/* for (int i = 0; i < count; i ++) { */
	/* 	printf("Positions are: %d\n", *(pos + i)); */
	/* } */
	printf("\nNames are: ");
	for (int i = 0; i < count; i++) {
		printf("%s\n", (name[i]));
	}
	free(name);
	return 0;
}
// >>>
