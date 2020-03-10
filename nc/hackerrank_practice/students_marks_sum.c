/** Name -> Abhay Shanker Pathak
Date -> 2020-03-09
Description -> give total marks for boys or for girls
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-09 */

#include<stdio.h>
#include<stdlib.h>

int marks_summation(int *, int , char);

int main(int argc, char *argv[]){
	int num_of_students;
	char gender;
	int sum;

	printf("\nEnter the total number of students in class: ");
	scanf("%d", &num_of_students);

	int *marks = (int *)malloc(num_of_students * sizeof(int));

	printf("\nEnter marks for each student: ");
	for (int student = 0; student < num_of_students; student++) {
		printf("\n%d: ", student + 1);
		scanf("%d", (marks + student));
	}

	printf("\nEnter the gender:\n'b' for boys and 'g' for girls: ");
	scanf("%s", &gender);

	sum = marks_summation(marks, num_of_students, gender);

	printf("\nTotal marks will be: %d", sum);
	free(marks);
	return 0;
}

int marks_summation(int *marks, int num_of_students, char gender) {
	int sum = 0;
	if (gender == 'b') {
		while (num_of_students >= 0) {
			if (num_of_students%2 != 0)
				sum += *(marks + num_of_students - 1);
			num_of_students--;
		}
	}
	else {
		while (num_of_students >= 0) {
			if (num_of_students%2 == 0)
				sum += *(marks + num_of_students - 1);
		num_of_students--;
		}
	}
	return sum;
}
