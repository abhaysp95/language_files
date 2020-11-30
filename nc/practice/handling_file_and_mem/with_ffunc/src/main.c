// main file

#include <stdio.h>

int main(int argc, char **argv) {
	FILE* file_to_read = fopen("some_data.txt", "r");
	FILE* file_to_write = fopen("some_written_data.txt", "w");

	if ((file_to_read == NULL) || (file_to_write == NULL)) {
		printf("One file couldn't open!\n");
		return -1;
	}

	char c;
	while ((c = fgetc(file_to_read)) && (c != EOF)) {
		if (c == '.') {
			c = '!';
		}
		fputc(c, file_to_write);
	}
	fclose(file_to_read);
	fclose(file_to_write);
	return 0;
}


/**
  * functions of f family:
  * fopen()
  * fread()
  * fwrite()
  * fprintf()
  * fscanf()
  * feof()
  * fclose()
  * fgetc()
  * fputc()
  */