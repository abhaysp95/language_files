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
	int count, f = 0;
	char **name;
	char *keyword;
	printf("\nEnter the count of names: ");
	scanf("%d\n", &count);

	/* char *name = (char *)malloc((count * 100) * (sizeof(char))); */
	name = malloc(count * sizeof(char *));

	printf("\nEnter the names: \n");
	for (int i = 0; i < count; i++) {
		name[i] = malloc(100 * sizeof(char));
		scanf("%[^\n]%*c", (name[i]));
		/* fgets(name[i], sizeof(name[i]), stdin); */
		// taking names without spaces
		/* scanf("%s", name[i]); */
		printf("length of string is: %zu\n", strlen(name[i]));
	}

	printf("\nEnter the keyword: \n");
	keyword = malloc(sizeof(char) * 50);
	/* scanf("%s", keyword); */
	scanf("%[^\n]%*c", keyword);

	printf("\nNames are: ");
	for (int i = 0; i < count; i++) {
		printf("%s\n", (name[i]));
	}

	// comparing logic
	for (int i = 0; i < count; i++) {
		if (strcmp(name[i], keyword) == 0) {
			printf("Name found, Position %d", i + 1);
			f++;
			break;
		}
	}
	if (f == 0) {
		printf("Name not found");
	}

	//testing
	/* printf("Names are: %s\n", name); */
	/* for (int i = 0; i < count; i ++) { */
	/* 	printf("Positions are: %d\n", *(pos + i)); */
	/* } */

	free(name);
	return 0;
}
// >>>
