/** Name -> Abhay Shanker Pathak
Date -> 2020-05-05
Description -> list files of directory
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-05-05 */


#include<stdio.h>

// main function <<<
int main(int argc, char* argv[]) {
	FILE *fp;
	char str[128];
	fp = popen("ls", "r");
	ftell(fp);
	fgets(str, 60, fp);
	ftell(fp);
	printf("%s\n", str);
	fclose(fp);
	return 0;
}
