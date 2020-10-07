#include <stdio.h>
#include <stdlib.h>
#define PRG_NAME "EasyLine"

void error_exit(unsigned int error_n) {
	char *error_msg[] = {
		"Unknown error code\n",
		"Insufficient memory.\n",
		"Illegal memory access.\n" };
	unsigned int arr_len = sizeof(error_msg) / sizeof(char *);
	if (error_n > arr_len) {
		error_n = 0;
	}
	/*fputs(error_msg[error_n], stderr);*/
	fputs(*(error_msg + error_n), stderr);
	exit(1);
}

int main(int argc, char **argv) {
	// wide character string representation
	double angle_alpha = 90.0/3;
	/*wchar_t str[] = {L"Angle \u03b1 measures %lf degrees.\n", angle_alpha};
	wprintf("%s", str);  // wprintf is the wide-character version of the printf*/
	wprintf(L"Angle \u03b1 measures %lf degrees.\n", angle_alpha);

	char msg[] = "The installation of " PRG_NAME " is now complete.";
	printf("%s\n", msg);

	error_exit(2);
	return 0;
}

/* Like characters, you can have wide strings with L, u or U prefixes of type
 * wchar_t, char16_t or char32_t's static null-terminated array. The array is
 * initialized by converting the multibyte charactes in the string literal to
 * wide characters in the same way as the standard function mbstowsc(), mbrtoc16
 * or mbrtoc32() would do */

/* you can break a string literal in several lines with \ */

/* there's a behaviour in this program something like the second printing string will not print starting from main() */
