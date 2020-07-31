// sum for unkown number of int inputs

#include <stdio.h>


// fix this

// main function
int main(int argc, char* argv[]) {
	int sum = 0, value = 0;
	printf("Get sum at runtime: ");
	/*while (1) {
		value = getchar();
		if (value == EOF) {
			break;
		}
		printf("%d\n", (int)(value));
		sum += (int)(value);
	}*/

	/*while ((value = getchar()) != EOF) {
		putchar(value);
		printf("\n");
		printf("1. Value without '-'(should be ascii of number): %d \n", value);
		printf("2. Value with '-'(should be number): %d \n", value - '0');
		printf("3. Value in char: %c\n", value);
		printf("4. Value after '-': %d\n", value - (int)('0'));
		// sum += (value - '0');
	}*/

	/*while((value = getchar()) != '\n' && value != EOF) {
		if (value != ' ') {
			printf("%d", value - (int)('0'));
			sum += value - (int)('0');
		}
	}*/

	while ((value = getchar()) != EOF) {
		if (value != ' ' && value != '\n') {
			if (value >= '0' && value <= '9') {
				sum += value - (int)('0');
			}
			else {
				break;
			}
		}
	}
	printf("\nSum is: %d\n", sum);

	/*while (( value = getchar()) != EOF ) {*/
		/*if ( value != '\n' || value != ' ' ) {*/
			/*printf("%d", (char)(value));*/
			/*printf("%")*/
		/*}*/
	/*}*/

	return 0;
}
